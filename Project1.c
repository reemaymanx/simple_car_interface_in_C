/*
 ============================================================================
 Name        : Project1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include <string.h>
#include<math.h>


//returns car speed by traffic color input
int traffic_light(int color){
	switch(color){
	case 'G':
	case 'g':
		return 100;

	case'o':
	case'O':
		return 30;
	case 'r':
	case'R':
		return 0;
	}
	return -1;
}
//setting car room temperature by inserting outside temperature whether it's too hot or too cold or neither
//modifies car room temperature too
bool setcartemp(int * temp){
	if(*temp <= 10){
		*temp =20;
		return true;
	}
	else if(*temp>=30){
		*temp = 30;
		return true;
	}
return false;
}
//returns engine controller state by inserting car engine temperature as it modifies engine temperature too
bool setengtemp(int *eng_temp){
if(*eng_temp <100){
	*eng_temp= 125;
	return true;
}
else if(*eng_temp >150){
	*eng_temp =125;
	return true;
}
return false;
}
//car room temperature according to its speed
void modifycartemp(int speed ,bool *ACstate, bool * controllerstate, int * temperature , int *eng_temperature ){
	if(speed==30){
	*ACstate= true;
	*temperature= *temperature*(5/4)+1;
	*controllerstate= true;
	*eng_temperature= *eng_temperature*(5/4)+1;
	}
}

//case 1 major function
void carsystem(){
	int temperature, eng_temp,speed;
	char engine_state , color;
	bool AC_state, Engine_Contoller_state;
	printf("Vehicle Engine is ON: \n "
				"a-Turn off The engine(Y/N) \n ");
		fflush(stdout);
		scanf(" %c",&engine_state);
		if(engine_state =='N'|| engine_state=='n'){
            printf(	"Engine is ON continue data: \n"
            		"b-Set Traffic light color(G/O/R) \n "
				    "c-Set the room temperature(Temperature Sensor) \n "
				    "d-Set the engine temperature (Engine Temperature Sensor)");
            fflush(stdout);
			scanf(" %c",&color);
			scanf("%d %d",&temperature, &eng_temp);
			//car speed variable
			speed = traffic_light(color);
			// AC on or off variable
            AC_state=setcartemp(&temperature);
            // controller on or off variable
            Engine_Contoller_state = setengtemp(&eng_temp);
            printf("Engine state: ON\n");
            if(AC_state==true){
            	  printf("AC: ON\n");
            }
            else{
            	printf("AC:OFF\n");
            }
            printf("Vehicle Speed: %d \n", speed);
            printf("Room Temperature: %d \n", temperature);
            if(Engine_Contoller_state==true){
            	printf("Engine Temperature Controller State: ON\n");
            }
            else{
            	printf("Engine Temperature Controller State: OFF\n");
            }
            printf("Engine Temperature: %d\n",eng_temp);
		}
		else{
          printf("Engine State: OFF\n");
		}
}



int main(void) {
	int choice;
	char n;
	printf(" Please Enter your choice:\n 1-Turn on vehicle engine \n 2-Turn off vehicle engine \n 3-Quit\n");
	fflush(stdout);
	scanf("%d",&choice);
	switch(choice){
	case 1:
		//generic function to be used in case 1 and case 2 if user didn't want to shut down
	carsystem();
		break;
	case 2:
		 do{

			printf("Are you sure you want to Turn off the vehicle?(1-yes , 2-no)\n");
			fflush(stdout);
			scanf(" %c",&n);
			if(n=='n'|| n=='N'){
				printf(" Please Enter your choice:\n 1-Turn on System \n 2-Turn off vehicle \n 3-Quit\n");
				fflush(stdout);
				scanf("%d",&choice);
				if(choice ==1){
				carsystem();
				break;
				}
				else if(choice ==3){
					printf("You QUIT....");
						return 0;
				}
			}
			else if(n=='y'||n=='Y'){
				printf("!!Vehicle is turned off!!");
				return 0;
			}
		}while(choice==2);
		break;
	case 3:
		printf("You QUIT....");
		return 0;
	}


	return 0;
}
