#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>


void main(){

	int sd ; 
	char msg [255];
	struct sockaddr_in adresse ;

	sd = socket(AF_INET , SOCK_STREAM ,0);
	if(sd<0)
		printf("Error of connection \n");
		

	adresse.sin_family=AF_INET;
	adresse.sin_port =1230;
	adresse.sin_addr.s_addr=INADDR_ANY;

	connect(sd, (struct sockaddr*)&adresse , sizeof(adresse));
	 while(1){

        printf("Enter Your Message : ");
        fgets(msg , sizeof(msg) ,stdin);
        send(sd , msg ,sizeof(msg) ,0);

        msg[strcspn(msg , "\n")]=0;
           if(strcmp(msg ,"good by")==0){
            	printf("Fin of comminication. \n");
            	break;

            }
           

        recv(sd , msg , sizeof(msg ) , 0);
        printf("server repence is : %s\n", msg );

     

    }

  
	close(sd);
 }   
