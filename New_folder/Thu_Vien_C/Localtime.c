#include<stdio.h>
#include<time.h>
int main(){
				time_t rawtime;
 				struct tm * timeinfo;
  				time ( &rawtime );
  				timeinfo = localtime ( &rawtime );
  				printf ( "Current local time and date: %s\n%d", asctime (timeinfo),timeinfo->tm_mday );
  				return 0;
}
