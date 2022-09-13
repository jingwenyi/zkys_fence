/**************************************
**
**  author: jingwenyi
**  date: 2022.8.17
**
***************************************/


#include <stdio.h>
#include <stdlib.h>



/*
* WGS84, EGM96 ellipsoid
*/
struct zkys_location
{
	float lng;  //Longitude (WGS84, EGM96 ellipsoid)
	float lat;  //Latitude (WGS84, EGM96 ellipsoid)
};



/*
 *
 * function : zkys location update
 * paramter:
 *		loc: input a old loc, output a new loc
 *		brearing: the brearing of from the old loc to the new loc, unit 0~360
 *		distance: the distance of from the old loc to the new loc, unit m
 */
void zkys_location_update(struct zkys_location *loc, float bearing, float distance);

/*
*  function : zkys check fence
*  paramter: 	
*		gps_loc : current machine position 
*		distance : input fence distance,output the minimum distance of from current to boundary. if  -1.0f is indicative of error. unit is m
*  return: 
*        	-1 is indicative of error,
*		0 is indicative of machine is not in fence,
*		1 is indicative of machine is in fence.
*/
int zkys_check_fence(struct zkys_location *gps_loc, float *distance);

/*
* function : zkys get brearing
* paramter:
*		loc1: the first loc.
*		loc2: the second loc.
* return : the brearing of from loc1 to loc2
*/
float zkys_get_bearing(const struct zkys_location *loc1, const struct zkys_location *loc2);

/*
* function : zkys get distance
* paramter:
*		loc1: the first loc.
*		loc2: the second loc.
* return : the distance of from loc1 to loc2, unit is m.
*/
float zkys_get_distance(const struct zkys_location *loc1, const struct zkys_location *loc2);

/*
* function : zkys wrap 360
* paramter: angle is input angle, for example:799, -355
* return : angle (scale is from 0 to 360)
*/
double zkys_wrap_360(const double angle);


