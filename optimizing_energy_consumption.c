#include <stdio.h>
#include<stdlib.h>

int main()
{
    //representing the room with a suitable matrix
    int room[4][4] = {0};
    //initializing the electrical equipments with OFF condition
    int fans_lights[2][2] = {0},ac[1][2] = {0};
    int rfid;
    //assuming base RFID value to be 14567.
    int base_rfid = 14567;
    //considering the office cabin to be split into slots
    int slot_1 = 0, slot_2 = 0, slot_3 = 0, slot_4 = 0;
    printf("Show the card in front of the RFID scanners\n");
    while(scanf("%d",&rfid) > 0)
    {
        int c = 0;
        int temp = rfid;
        rfid -= base_rfid;
        int temp0 = rfid;
        if(rfid <= 4)
        {
            room[0][rfid] = 1;
        }
        else
        {
            while(rfid > 4)
            {
                rfid -= 4;
                c++;
            }
            room[c][(temp-(base_rfid+(4*c)))-1] = 1;
        }
        printf("\noffice cabin occupied staus(0-ON/1-OFF)");
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                printf("%d ",room[i][j]);
            }
            printf("\n");
        }
        if(slot_1 < 4)
        {
            slot_1++;
        }
        else if(slot_2 < 4)
        {
            slot_2++;
        }
        else if(slot_3 < 4)
        {
            slot_3++;
        }
        else if(slot_4 < 4)
        {
            slot_4++;
        }
        else
        {
            //if the room has attained its capacity, display corresponding message and deny entry to the room
            printf("Room full\n");
            return 0;
        }
        printf("slots: %d %d %d %d\n",slot_1, slot_2, slot_3, slot_4);
    }
    if(slot_1 >= 2 && fans_lights[0][0] != 1)
    {
        fans_lights[0][0]++;
    }
    if(slot_2 >= 2 && fans_lights[0][1] != 1)
    {
        fans_lights[0][1]++;
    }
    if(slot_3 >= 2 && fans_lights[1][0] != 1)
    {
        fans_lights[1][0]++;
    }
    if(slot_4 >= 2 && fans_lights[1][1] != 1)
    {
        fans_lights[1][1]++;
    }
    printf("\nfans_lights state(0-ON/1-OFF)\n");
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            printf("%d ",fans_lights[i][j]);
        }
        printf("\n");
    }
    if(fans_lights[0][0] == 1 && fans_lights[0][1] == 1)
    {
        ac[0][1]++;
    }
    if(fans_lights[1][0] == 1 && fans_lights[1][1] == 1)
    {
        ac[0][2]++;
    }
    printf("\nAC state(0-ON/1-OFF)\n");
    for(int j = 0; j < 2; j++)
    {
        printf("%d ",ac[0][j]);
    }
    return 0;
}
