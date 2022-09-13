/*
**
** test zkys_fence example.
**
*/

#include "fence.h"


int main()
{
	int ret;
	float ret_f;
	float distance = 500.0f;
	struct zkys_location gps_loc;
	struct zkys_location calculate_new;

	//test function	
	gps_loc.lat = 49.3265212;
	gps_loc.lng = 115.5937500;

	calculate_new.lat = 49.3265212;
	calculate_new.lng = 115.5937500;

	// input bearing is 60, distance 200 m
	zkys_location_update(&calculate_new, 60, 200);

	printf("callculate new lat:%f, lng:%f\n", calculate_new.lat, calculate_new.lng);

	ret_f = zkys_get_bearing(&gps_loc, &calculate_new);
	printf("bearing: %f\n", ret_f);

	ret_f = zkys_get_distance(&gps_loc, &calculate_new);
	printf("distance:%f\n", ret_f);

	ret_f = zkys_wrap_360(399.66);
	printf("angle test1:%f\n", ret_f);

	ret_f = zkys_wrap_360(-399.66);
	printf("angle test2:%f\n", ret_f);


	// the first boundary point test
	printf("----test the first boundary point------\n");
	gps_loc.lat = 49.854168;
	gps_loc.lng = 116.729393;

	//test1
	calculate_new.lat = 49.854168;
	calculate_new.lng = 116.729393;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 60, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test1 in (1) or out (0):%d, distance: %f\n", ret, distance);

	//test2
	calculate_new.lat = 49.854168;
	calculate_new.lng = 116.729393;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 120, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test2 in (1) or out (0):%d, distance: %f\n", ret, distance);


	//test3
	calculate_new.lat = 49.854168;
	calculate_new.lng = 116.729393;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 180, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test3 in (1) or out (0):%d, distance: %f\n", ret, distance);

	//test4
	calculate_new.lat = 49.854168;
	calculate_new.lng = 116.729393;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 240, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test4 in (1) or out (0):%d, distance: %f\n", ret, distance);


	
	//test5
	calculate_new.lat = 49.854168;
	calculate_new.lng = 116.729393;
	
	distance = 500.0f;
	zkys_location_update(&calculate_new, 300, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test5 in (1) or out (0):%d, distance: %f\n", ret, distance);


	//test6
	calculate_new.lat = 49.854168;
	calculate_new.lng = 116.729393;
	
	distance = 500.0f;
	zkys_location_update(&calculate_new, 360, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test6 in (1) or out (0):%d, distance: %f\n", ret, distance);



	//last boundary point test
	printf("----test the last boundary point------\n");
	gps_loc.lat = 49.172311;
	gps_loc.lng = 87.829301;

	//test1
	calculate_new.lat = 49.172311;
	calculate_new.lng = 87.829301;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 60, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test1 in (1) or out (0):%d, distance: %f\n", ret, distance);

	//test2
	calculate_new.lat = 49.172311;
	calculate_new.lng = 87.829301;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 120, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test2 in (1) or out (0):%d, distance: %f\n", ret, distance);


	//test3
	calculate_new.lat = 49.172311;
	calculate_new.lng = 87.829301;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 180, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test3 in (1) or out (0):%d, distance: %f\n", ret, distance);

	//test4
	calculate_new.lat = 49.172311;
	calculate_new.lng = 87.829301;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 240, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test4 in (1) or out (0):%d, distance: %f\n", ret, distance);


	
	//test5
	calculate_new.lat = 49.172311;
	calculate_new.lng = 87.829301;
	
	distance = 500.0f;
	zkys_location_update(&calculate_new, 300, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test5 in (1) or out (0):%d, distance: %f\n", ret, distance);


	//test6
	calculate_new.lat = 49.172311;
	calculate_new.lng = 87.829301;
	
	distance = 500.0f;
	zkys_location_update(&calculate_new, 360, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test6 in (1) or out (0):%d, distance: %f\n", ret, distance);


	//other  boundary point test
	printf("----test the nomal boundary point------\n");
	gps_loc.lat = 41.669091;
	gps_loc.lng = 104.527308;

	//test1
	calculate_new.lat = 41.669091;
	calculate_new.lng = 104.527308;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 60, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test1 in (1) or out (0):%d, distance: %f\n", ret, distance);

	//test2
	calculate_new.lat = 41.669091;
	calculate_new.lng = 104.527308;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 120, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test2 in (1) or out (0):%d, distance: %f\n", ret, distance);


	//test3
	calculate_new.lat = 41.669091;
	calculate_new.lng = 104.527308;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 180, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test3 in (1) or out (0):%d, distance: %f\n", ret, distance);

	//test4
	calculate_new.lat = 41.669091;
	calculate_new.lng = 104.527308;

	distance = 500.0f;
	zkys_location_update(&calculate_new, 240, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test4 in (1) or out (0):%d, distance: %f\n", ret, distance);


	
	//test5
	calculate_new.lat = 41.669091;
	calculate_new.lng = 104.527308;
	
	distance = 500.0f;
	zkys_location_update(&calculate_new, 300, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test5 in (1) or out (0):%d, distance: %f\n", ret, distance);


	//test6
	calculate_new.lat = 41.669091;
	calculate_new.lng = 104.527308;
	
	distance = 500.0f;
	zkys_location_update(&calculate_new, 360, 700);
	ret = zkys_check_fence(&calculate_new, &distance);
	printf(" test6 in (1) or out (0):%d, distance: %f\n", ret, distance);

	return 0;
}






