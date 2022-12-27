#include "global.h"
#include "rtc.h"
#include "constants/time.h"
#include "overworld.h"
#include "time.h"

bool8 ShouldTintOverworld(void){
    return (IsMapTypeOutdoors(gMapHeader.mapType));
}

u8 GetCurrentTimeOfDay(void)
{
    if(gLocalTime.hours >= TIME_DAWN && gLocalTime.hours < TIME_DUSK){
        return TIME_MID_DAY;
    }
    else if(gLocalTime.hours >= TIME_MID_DAY && gLocalTime.hours < TIME_MID_NIGHT){
        return TIME_DUSK;
    }
    else if(gLocalTime.hours >= TIME_DUSK){
        return TIME_MID_NIGHT;
    }else{
        return TIME_DAWN;
    }
}