#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100 // Maximum number of flights that can be stored

// Define a struct to hold flight information
struct Flight {
    int number;
    int type;
    char from[50];
    char to[50];
    char date[20];
    char time[10];
};

int main() {
    struct Flight flights[MAX_FLIGHTS]; // Array of flights
    int num_flights = 0; // Number of flights currently in the array
    FILE* fp; // Pointer to file
    char filename[] = "flights.txt"; // Name of file containing flight information
    char line[200]; // Buffer for reading each line of the file
    char* token; // Pointer to token within line
    

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Read each line of file, parse flight information, and store in array
    while (fgets(line, 100, fp) != NULL) {
        token = strtok(line, ",");
        flights[num_flights].number=atoi(token);
        token = strtok(NULL, ",");
        flights[num_flights].type=atoi(token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].from, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].to, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].date, token);
        token = strtok(NULL, ",");
        strcpy(flights[num_flights].time, token);
        num_flights++;
    }
    // Close file
    fclose(fp);
    
    
    while(1){
    printf("Menu:\n");
    printf("1. Add a flight\n");
    printf("2. Update a flight\n");
    printf("3. Search for a flight with departure city\n");
    printf("4. Search for a flight with arrival city\n");
    printf("5. List all flights\n");
    printf("6. Exit\n");
    printf("7. Delete a flight\n");
    int choice;
    wrong_choice:
    printf("Enter your choice (1-7): ");
    scanf("%d",&choice);
    
    struct Flight neww;
    int i,j;
    int new_choice;
    int update,position,deletee,delete_position;
    int compare;
    int compare_2;
    char origin[20];
    char destination[20];
    
    switch(choice){
    	case 1:
    		fp = fopen(filename,"a"); //add
    	    printf("Enter a flight number: ");
    		scanf("%d",&neww.number);
    		fprintf(fp,"\n");
    		fprintf(fp,"%d",neww.number);
    		
    		printf("Enter flight type 1 for domestic 0 for international flights: ");
    		scanf("%d",&neww.type);
    		fprintf(fp,",");
    		fprintf(fp,"%d",neww.type);
    		
    		printf("Enter the departure city of the flight: ");
    		scanf("%s",&neww.to);
    		fprintf(fp,",");
    		fprintf(fp,"%s",neww.to);
    		
    		printf("Enter the arrival city of the flight: ");
    		scanf("%s",&neww.from);
    		fprintf(fp,",");
    		fprintf(fp,"%s",neww.from);
    		
    		printf("Enter the flight date: ");
    		scanf("%s",&neww.date);
    		fprintf(fp,",");
    		fprintf(fp,"%s",neww.date);
    		   
    		getchar();               //for using together scanf and gets
    		printf("Enter the flight time: ");
    		gets(neww.time);
    		fprintf(fp,",");
    		fprintf(fp,"%s",neww.time);
    	
    		printf("Flight inserted succesfully!\n");
    		break;
    	case 2:
    		printf("Enter flight number to update: ");
    		scanf("%d",&update);
    		for(i=0;i<num_flights;i++){
    			if(update==flights[i].number){
    				position=i;
    				printf("Flight found.Which field would you like to update?\n");
				}
			}
			printf("1. Type\n2. From\n3. To\n4. Date\n5. Time\n");
			printf("Enter your choice (1-5): ");
			scanf("%d",&new_choice);
			switch(new_choice){
				case 1:
					printf("Enter your new type: ");
					scanf("%d",&flights[position].number);
					break;
				case 2:
					printf("Enter your new departure: ");
					scanf("%s",&flights[position].from);
					break;
				case 3:
					printf("Enter your new arrival: ");
					scanf("%s",&flights[position].to);
					break;
				case 4:
					printf("Enter your new date: ");
					scanf("%s",&flights[position].date);
					break;
				case 5:
					printf("Enter your new time: ");
					scanf("%s",&flights[position].time);
					break;
			}
			printf("Flight updated successfully.\n");
    		break;
    	case 3:
    		printf("Enter origin: ");
    		scanf("%s",&origin);
    		printf("Flights from %s\n",origin);
    		for(i=0;i<num_flights;i++){
    			compare=strcmp(origin,flights[i].from);
    			if(compare==0){
    				printf("%d\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\n",flights[i].number,
			        flights[i].type,flights[i].from,flights[i].to,
			        flights[i].date,flights[i].time);
				}
			}
    		break;
    	case 4:
    		printf("Enter destination: ");
    		scanf("%s",&destination);
    		printf("Flights to %s\n",destination);
    		for(i=0;i<num_flights;i++){
    			compare_2=strcmp(destination,flights[i].to);
    			if(compare_2==0){
    				printf("%d\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\n",flights[i].number,
			        flights[i].type,flights[i].from,flights[i].to,
			        flights[i].date,flights[i].time);
				}
			}
    		break;
    	case 5:
    		printf("FNum\t\tD/I\t\tfrom\t\tto\t\tDate\t\tTime\n");
    		for(i=0;i<num_flights;i++){
    			printf("%d\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\n",flights[i].number,
			    flights[i].type,flights[i].from,flights[i].to,
			    flights[i].date,flights[i].time);
			}
			printf("\n");
			break;
		case 6:
			exit(0);
		case 7:
			printf("Enter flight number to delete: ");
			scanf("%d",&deletee);
			for(i=0;i<num_flights;i++){
				if(deletee==flights[i].number){
					delete_position=i;
				}
			}
			for(j=delete_position-1;j<num_flights-1;j++){
				flights[j].number=flights[j+1].number;
			}
			break;
    	default:
    		printf("You must enter the number 1 between 7!!\n");
    		goto wrong_choice;
    		break;
	}
    }
    
    

    return 0;
}

