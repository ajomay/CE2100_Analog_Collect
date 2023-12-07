// #############################################################################
//  ScalintToolsGenII.C
//
//
//
//  Created: 20.08.2023
//  History:
//
//  (C) ce.tron Gesellschaft f�r Hard-& Softwaretechnik mbH
//  Roentgenstrasse 104
//  D-64291 Darmstadt
// #############################################################################

#include "Debug.h"

//-------------------------------------------------------------------
//
#include "ScalintToolsGenII.h"

/*
#ifdef _DEB_FLAG_DEBUG_
sprintf(DebStr, "Mot: %d", (int)(State));
Serial.println(DebStr);
#endif
*/

//--------------------------------------------------------------------------------
//
TSLONG32 SctGgt(TSLONG32 a, TSLONG32 b)
{
    if (a < 0)
    {
        a = -a;
    }

    if (b < 0)
    {
        b = -b;
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//-------------------------------------------------------------------
//
TSLONG32 SctDoScaling(SctScalingStruct *pS, TSLONG32 X)
{
    TSLONG32 Result;

    Result = X * pS->Mz;

    Result /= pS->Mn;

    Result += pS->B;

#ifndef SCT_USE_SMALL_STRUCT
    if (Result > pS->YMax)
    {
        Result = pS->YMax;
    }
    else
    {
        if (Result < pS->YMin)
        {
            Result = pS->YMin;
        }
    }
#endif

    return Result;
}

//-------------------------------------------------------------------
// WARNING:
// NO local storage of parameters in static variables.
// Allways call this function with all parameters full valid!
//
TSTATEVALUE SctDoScaling(TSTATEVALUE *pState, TSLONG32 *pResult, SctScalingStruct *pS, TSLONG32 X)
{

    switch (*pState)
    {
        //--------------------
    case 0:
        break;

        //--------------------
    case 1:
        *pResult = X * pS->Mz;
        (*pState)++;
        break;

        //--------------------
    case 2:
        *pResult /= pS->Mn;
        (*pState)++;
        break;

        //--------------------
    case 3:
        *pResult += pS->B;
#ifndef SCT_USE_SMALL_STRUCT
        if (*pResult > pS->YMax)
        {
            *pResult = pS->YMax;
        }
        else
        {
            if (*pResult < pS->YMin)
            {
                *pResult = pS->YMin;
            }
        }
#endif
        (*pState) = 0;
        break;

        //--------------------
        //--------------------
    default:
        (*pState) = 0;
    }

    return (*pState);
}

//-------------------------------------------------------------------
//
TSLONG32 SctDoScalingNoB(SctScalingStruct *pS, TSLONG32 X)
{
    TSLONG32 Result;

    Result = X * pS->Mz;

    Result /= pS->Mn;

    return Result;
}

//-------------------------------------------------------------------
//
TUCHAR SctSetScalingStruct(SctScalingStruct *pS, TSLONG32 X1, TSLONG32 Y1, TSLONG32 X2, TSLONG32 Y2, TSLONG32 Ymin, TSLONG32 Ymax)
{
#ifndef SCT_USE_SMALL_STRUCT
    pS->X1 = X1;
    pS->Y1 = Y1;
    pS->X2 = X2;
    pS->Y2 = Y2;
#endif

    if (((X2 - X1) == 0) || ((Y2 - Y1) == 0))
    {
        Serial.println("POINT DISTANCE MUST NOT BE 0!");
        return 1;
    }

#ifndef SCT_USE_SMALL_STRUCT
    if (Ymin >= Ymax)
    {
        Serial.println("Y-Limits invalid!");
        return 1;
    }

    pS->YMin = Ymin;
    pS->YMax = Ymax;
#endif

    TSLONG32 Z, N;

    Z = (Y2 - Y1);
    N = (X2 - X1);

    TSLONG32 Ggt = SctGgt((Y2 - Y1), (X2 - X1));

#ifdef _DEB_FLAG_DEBUG_
    sprintf(DebStr, "SctSetScalingStruct: Z= %ld N= %ld GGT=%ld", Z, N, Ggt);
    Serial.println(DebStr);
#endif

    pS->Mz = Z / Ggt;
    pS->Mn = N / Ggt;

    pS->B = Y2 - SctDoScalingNoB(pS, X2);

#ifdef _DEB_FLAG_DEBUG_
    TSLONG32 Yf1 = SctDoScalingNoB(pS, X1);
    TSLONG32 Yf2 = SctDoScalingNoB(pS, X2);
    TSLONG32 Bb1 = Y1 - SctDoScalingNoB(pS, X1);
    TSLONG32 Bb2 = Y2 - SctDoScalingNoB(pS, X2);

    TSLONG32 Err1, Err2, Err;

    Err1 = Y1 - Yf1;
    Err2 = Y2 - Yf2;

    Err = SctAbsDiff_(Err2, Err1);

    sprintf(DebStr, "Sct: X1= %ld, Y1= %ld X2= %ld Y2= %ld ", (TSLONG32)X1, (TSLONG32)Y1, (TSLONG32)X2, (TSLONG32)Y2);
    Serial.print(DebStr);
    sprintf(DebStr, "Yf1= %ld, Yf2= %ld B1= %ld B2= %ld ", Yf1, Yf2, Bb1, Bb2);
    Serial.print(DebStr);
    sprintf(DebStr, "M=%ld/%ld E1=%ld E2 %ld E=%ld\n", pS->Mz, pS->Mn, Err1, Err2, Err);
    Serial.println(DebStr);
#endif

#ifdef SCT_GENERATE_C_CODE
{
    char Msg[128];
    sprintf(Msg, "\npS->X1=%ld; pS->Y1=%ld; pS->X2=%ld; pS->Y2=%ld;", (TSLONG32)X1, (TSLONG32)Y1, (TSLONG32)X2, (TSLONG32)Y2);
    Serial.println(Msg);
    sprintf(Msg, "pS->Mz=%ld; pS->Mn=%ld; pS->B=%ld;", (TSLONG32)pS->Mz, (TSLONG32)pS->Mn, (TSLONG32)pS->B);
    Serial.println(Msg);
    sprintf(Msg, "pS->YMin=%ld; pS->YMax=%ld;\n", (TSLONG32)pS->YMin, (TSLONG32)pS->YMax);
    Serial.println(Msg);
}
#endif
    return 0;
}

//-------------------------------------------------------------------
//
void SctPrintSctScalingStruct(SctScalingStruct *pS, const char *pName)
{
    char Msg[128];

    sprintf(Msg, "\n%s;", pName);
    Serial.print(Msg);

#ifndef SCT_USE_SMALL_STRUCT
    sprintf(Msg, "%ld;%ld;%ld;%ld;", pS->X1, pS->Y1, pS->X2, pS->Y2);
    Serial.print(Msg);
    sprintf(Msg, "%ld;%ld;", pS->YMin, pS->YMax);
    Serial.print(Msg);
#else
    sprintf(Msg, "00;00;00;00;");
    Serial.print(Msg);
    sprintf(Msg, "00;00;");
    Serial.print(Msg);
#endif
    sprintf(Msg, "%ld;%ld;%ld;\n", pS->Mz, pS->Mn, pS->B);
    Serial.println(Msg);

}

// #############################################################################
// #############################################################################
// #############################################################################
