#include "Adafruit_TLC59711.h"
#include <SPI.h>


#define NUM_TLC59711PERPANEL 10       //Number of TLC59711 Chips
#define NUM_PANELS 4                  //Number of Panels


#define data   6                      //Data Pin
#define clock  5                      //Clock Pin



Adafruit_TLC59711 tlc = Adafruit_TLC59711(NUM_TLC59711PERPANEL*NUM_PANELS, clock, data);

String  L = "0,1,16,18,24,3 1,2,6,16,0 2,7,5,6,1 3,0,89,24,94,95 4,11,8,12,5,7 5,4,12,19,21,6,2,7 6,1,2,7,5,19,21,20,18 7,2,6,5,4 8,11,10,9,14,12,4 9,10,8,14,15 10,11,8,9 11,4,8,10 12,8,14,13,19,5,4,8 13,22,23,15,14,12,19 14,9,8,12,13,15 15,9,14,13,23,31 16,1,18,17,25,24,0 17,18,20,27,26,25,16 18,16,1,6,21,20,27,17 19,6,5,12,13,22,21 20,18,6,21,33,34,35,27,17 21,6,5,19,22,33,34,20,18 22,28,23,13,19,21,33 23,15,13,22,28,31 24,3,0,16,25,36,95,111,103 25,16,17,26,36,111,24 26,17,27,32,37,36,25 27,17,20,34,35,32,26 28,23,31,29,33,22,51 29,31,28,51,48,49 30,31,29,55,54,48 31,15,23,28,29,30 32,26,27,35,39,38,37 33,20,21,22,28,34,51 34,27,20,21,33,51,45,44,35 35,32,27,20,34,44,45,46,39 36,24,25,26,37,111,109,110,43 37,36,26,32,38,43,110 38,37,32,39,43,40,41 39,38,32,35,41,46,45,47 40,41,56,64,43,38 41,42,46,58,56,40,38 42,47,45,46,41,35,38,41,32 43,38,37,36,64,135,134,129,40 44,51,48,52,45,47,34 45,44,52,59,61,46,42,47,34 46,41,42,47,45,59,61,60,58 47,42,46,45,44,34,20,27,32 48,51,50,49,54,52,44 49,50,48,54,55,31 50,51,48,49,31,28 51,44,48,50,34,33,28 52,48,54,53,59,45,44,48 53,62,63,55,54,52,59 54,49,48,52,53,63,55 55,49,54,53,63,71 56,41,58,57,65,64,40 57,58,67,66,65,56,60 58,56,41,46,61,60,57 59,46,45,52,53,62,61 60,58,46,61,73,74,75,67,57 61,46,45,59,62,73,74,60,58 62,68,63,53,59,61,73 63,55,53,62,68,71 64,43,40,56,65,76,135,151,143 65,56,57,66,76,151,64 66,57,67,72,77,76,65 67,57,60,74,75,72,66 68,63,71,69,73,62 69,71,68,70 70,71,69 71,55,63,68,69,70 72,66,67,75,79,78,77 73,60,61,59,62,68,74 74,67,60,61,73,75 75,72,67,60,74,79 76,64,65,66,77,151,150,149 77,76,66,72,78,150 78,77,72,79 79,78,72,75 80,81,96,98,104,83 81,82,86,96,98,80 82,87,85,86,81 83,80,104 84,91,88,92,85,87 85,84,92,99,101,86,82,87 86,81,82,87,85,99,101,100,98 87,82,86,85,84 88,91,90,89,94,92,84 89,90,88,94,95,3 90,91,88,89 91,84,88,90 92,88,94,93,99,85,84,88 93,102,103,95,94,92,99 94,89,88,92,93,95,3 95,89,94,93,103,111,3,24 96,81,98,97,105,104,80 97,98,100,107,106,105,96 98,96,81,86,101,100,107,97 99,86,85,92,93,102,101 100,98,86,101,113,114,115,107,97 101,86,85,99,102,113,114,100,98 102,108,103,93,99,101,113 103,95,93,102,108,111,24 104,83,80,96,105,116 105,96,97,106,116,104 106,97,107,112,117,116,105 107,97,100,114,115,112,106 108,103,111,109,113,102,131 109,111,108,131,128,129,36 110,111,109,135,134,128,36,43,37 111,95,103,108,109,110,36,24,25 112,106,107,115,119,118,117 113,100,101,102,108,114,131 114,107,100,101,113,131,125,124,115 115,112,107,100,114,124,125,126,119 116,104,105,106,117,123 117,116,106,112,118,123, 118,117,112,119,123,120,121 119,118,112,115,121,126,125,127 120,121,136,138,144,123,118 121,122,126,136,138,120,118 122,125,126,121,115,118,112 123,118,117,116,144,120 124,131,128,132,125,127,114 125,124,132,139,141,126,122,127,114 126,121,122,127,125,139,138,141,140 127,122,126,125,124,114,100,107,112 128,131,130,129,134,132,124 129,130,128,134,135,111,43,36,37 130,131,128,129,111,108 131,124,128,130,114,113,108 132,128,134,133,139,125,124,128 133,135,134,132,139,142,143 134,129,128,132,133,135,135,43 135,129,134,93,43,151,143,133 136,121,138,137,145,144,120 137,138,140,107,106,105,96 138,136,121,126,141,140,147,137 139,126,125,132,133,142,141 140,138,126,141,153,154,155,147,137 141,126,125,139,162,153,154,140,138 142,148,143,133,139,141,153 143,135,133,142,148,151,64 144,123,120,136,145,156 145,136,137,146,156,144 146,137,147,152,157,156,145 147,137,140,154,155,152,146 148,143,151,149,153,142,171 149,151,148,150,76 150,151,149,76,77 151,135,143,148,149,150,76,64,65 152,146,147,155,159,158,157 153,140,141,142,148,154 154,147,140,141,153,155 155,152,147,140,154,159 156,144,145,146,157 157,156,146,152,158 158,157,152,159 159,158,152,155";
String Ls[160];                             //Max StringCount for Non-Space String
String Neighbours[9];                       //Max StringCount for Non-Comma String (Altered with CommaCount)
int StringCount = 0;
int CommaCount = 0;
int i = 0;
const int Len = sizeof(Neighbours) / sizeof(Neighbours[0]);

int period = 100;                           //millis() variable
unsigned long time_now = 0;                 //millis() time_now


long randnum;                               //Starting Positions Random Number Generator
int s = 0;                                        //^^
int seqnum[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};     //^^
int LedID[160];                                        //^^



int LED[160];

int State[160];                             //Lifecycle logic
int GenNum;                                 //Generation Number
int AliveCount = 0;



void setup() {
  Serial.begin (9600);


  while (L.length() > 0)                    //Space Split Script (Stop When String is 0)
  {
    int index1 = L.indexOf(' ');            //Find All Spaces (identified as -1)
    if (index1 == -1)                       //If Found Break Line
    {
      Ls[StringCount++] = L;
      break;
    }
    else                                    //Otherwise,keep index at 0
    {
      Ls[StringCount++] = L.substring(0, index1);
      L = L.substring(index1 + 1);
    }
  }



  for (int i = 0; i < StringCount; i++)     //Comma Split Script (Output as Neighbours[i])
  {
    CommaCount = 0;
    String Ls2 = Ls[i];
    while (Ls2.length() > 0)
    {
      int index = Ls2.indexOf(',');
      if (index == -1)
      {
        Neighbours[CommaCount++] = Ls2;
        break;
      }
      else
      {
        Neighbours[CommaCount] = Ls2.substring(0, index);
        CommaCount++;
        Ls2 = Ls2.substring(index + 1);

      }
    }
  }







  tlc.begin();



  for (int ledindx = 0; ledindx < 160; ledindx++)
  {
    State[ledindx] = 0;
  }
  randomSeed(analogRead(0));                //Random Starting Positions
  s = 0;

  while (s <= 25)
  {
    randnum = random(160);
    if (seqnum[randnum - 1] == 0)
    {
      seqnum[randnum - 1] = 1;
      LedID[s] = randnum;
      TurnLED(LedID[s], 0, 65535/2, 32768/2, 0);
      State[LedID[s]] = 1;

      s++;

    }
  }

}









void loop() {                               //State 1 = Alive and 0 = Dead


  StringCount = 160;                        

  for (int i = 0; i < StringCount; i++)     //Comma Split Script (Output as Neighbours[i])
  {

    CommaCount = 0;
    String Ls3 = Ls[i];


    while (Ls3.length() > 0)
    {
      int index = Ls3.indexOf(',');
      if (index == -1)
      {
        Neighbours[CommaCount++] = Ls3;
        break;
      }
      else
      {
        Neighbours[CommaCount] = Ls3.substring(0, index);
        CommaCount++;
        Ls3 = Ls3.substring(index + 1);
      }
    }


    AliveCount = 0;                         //Reset AliveCount

    for (int j = 0; j < CommaCount; j++)    //Find How Many Cells are Alive Within Neighbour Boundary
    {
      AliveCount = State[Neighbours[j].toInt()] + AliveCount;
    }

    int LED = Neighbours[0].toInt();
    if (State[LED] == 1)                    //If cell is alive then these 3 rules apply
    {

      // Rule 1: Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
      if (AliveCount < 2)
      {
        State[LED] = 0;
      }

      // Rule 2: Any live cell with two or three live neighbours lives on to the next generation
      if (AliveCount == 3 || AliveCount == 2)
      {
        State[LED] = 1;
      }

      // Rule 3: Any live cell with more than three live neighbours dies, as if by overpopulation.
      if (AliveCount > 3)
      {
        State[LED] = 0;
      }
    }

    //Rule 4: Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    if (State[LED] == 0 && AliveCount == 3 )
    {
      State[LED] = 1;
    }
  }


  for (int i = 0; i < StringCount; i++)       //Play Actions at the Same Time (Delay Inncreases Duration)
  {
    TurnLED(i, 0, State[i] * 65535/2, State[i] * 32768/2, 0);
  }
  tlc.write();
  delay(200);


  if (GenNum == 200)
  {

    for (int ledindx = 0; ledindx < 160; ledindx++)     //Regenerate Random Starting Positions if Game Stagnates After 200 Generations
    {
      State[ledindx] = 0;
    }
    s = 0;

    while (s <= 25)
    {
      randnum = random(160);
      if (seqnum[randnum - 1] == 0)
      {
        seqnum[randnum - 1] = 1;
        LedID[s] = randnum;

        TurnLED(LedID[s], 0, 65535/2, 32768/2, 0);
        State[LedID[s]] = 1;

        s++;
      }
    }
    GenNum = 0;
  }

  GenNum++;


}//End Loop






void TurnLED(uint16_t i , uint16_t r, uint16_t g, uint16_t b, uint8_t wait)
{

  //Seam/Shared LEDs
  tlc.setLED(i, r, g, b);

  delay(wait);

  if (i == 39) {
    tlc.setLED(42, r, g, b);
  }
  if (i == 42) {
    tlc.setLED(9, r, g, b);
  }


  if (i == 35) {
    tlc.setLED(47, r, g, b);
  }
  if (i == 47) {
    tlc.setLED(35, r, g, b);
  }


  if (i == 29) {
    tlc.setLED(50, r, g, b);
  }
  if (i == 50) {
    tlc.setLED(29, r, g, b);
  }


  if (i == 30) {
    tlc.setLED(49, r, g, b);
  }
  if (i == 49) {
    tlc.setLED(30, r, g, b);
  }


  if (i == 47) {
    tlc.setLED(35, r, g, b);
  }
  if (i == 35) {
    tlc.setLED(47, r, g, b);
  }


  if (i == 50) {
    tlc.setLED(29, r, g, b);
  }
  if (i == 29) {
    tlc.setLED(50, r, g, b);
  }


  if (i == 119) {
    tlc.setLED(122, r, g, b);
  }
  if (i == 122) {
    tlc.setLED(119, r, g, b);
  }



  if (i == 115) {
    tlc.setLED(127, r, g, b);
  }
  if (i == 127) {
    tlc.setLED(115, r, g, b);
  }


  if (i == 109) {
    tlc.setLED(130, r, g, b);
  }
  if (i == 130) {
    tlc.setLED(129, r, g, b);
  }


  if (i == 110) {
    tlc.setLED(129, r, g, b);
  }
  if (i == 129) {
    tlc.setLED(110, r, g, b);
  }

}
