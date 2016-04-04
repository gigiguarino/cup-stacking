//
//  michiganLeagueCupStacking2.cpp
//  Created by Gabrielle Guarino on 9/13/15.


#include "michiganLeagueCupStacking2.h"

#include <iostream>
using namespace std;


int main(void)
{

   int num_cups;
   cout << "How many cups?: ";
   cin >> num_cups;
   bool already1 = false;
   bool already2 = false;
   bool already3 = false;
   bool already4 = false;
   int num_answers = 0;
   
   cout << "-----------------------" << endl;
   cout << "Options: " << endl;
   cout << "-----------------------" << endl;
   
   for (int a = 2; a <= 9; a++)
   {
      for (int b = 2; b <= 15; b++)
      {
         if (num_cups == (a*b) && !already1)
         {
            cout << "First level: " << a << "x" << b << endl;
            cout << "-----------------------" << endl;
            already1 = true;
            num_answers++;
         }
         
         else if (num_cups == ((a*b) + (a-1)*(b-1)) && !already2 && (a-1) > 0 && (b-1) > 0)
         {
            cout << "First level: " << a << "x" << b << endl;
            cout << "Second level: " << a-1 << "x" << b-1 << endl;
            cout << "-----------------------" << endl;
            already2 = true;
            num_answers++;
         }
         
         else if (num_cups == ((a*b) + (a-1)*(b-1) + (a-2)*(b-2)) && !already3 && (a-1) > 0 && (b-1) > 0 && (a-2) > 0 && (b-2) > 0)
         {
            cout << "First level: " << a << "x" << b << endl;
            cout << "Second level: " << a-1 << "x" << b-1 << endl;
            cout << "Third level: " << a-2 << "x" << b-2 << endl;
            cout << "-----------------------" << endl;
            already3 = true;
            num_answers++;
         }
         
         else if (num_cups == ((a*b) + (a-1)*(b-1) + (a-2)*(b-2) + (a-3)*(b-3)) && !already4 && (a-1) > 0 && (b-1) > 0 && (a-2) > 0 && (a-2) > 0 && (a-3) > 0 && (b-3) > 0)
         {
            cout << "First level: " << a << "x" << b << endl;
            cout << "Second level: " << a-1 << "x" << b-1 << endl;
            cout << "Third level: " << a-2 << "x" << b-2 << endl;
            cout << "Fourth level: " << a-3 << "x" << b-3 << endl;
            cout << "-----------------------" << endl;
            already4 = true;
            num_answers++;
         }
      }
   }
   
   if (num_answers <= 2 && num_cups > 18)
   {
      int difference = 1000;
      int finalA;
      int finalB;
      
      already2 = false;
      already3 = false;
      already4 = false;

      for (int a = 2; a <= 9; a++)
      {
         for (int b = 2; b <= 13; b++)
         {
            if (num_cups > ((a*b) + (a-1)*(b-1)) && (num_cups - ((a*b) + (a-1)*(b-1))) < difference && !already2 && (b-1) > 0 && (a-1) > 0)
            {
               finalA = a;
               finalB = b;
               difference = num_cups - ((a*b) + (a-1)*(b-1));
               already2 = true;
               already3 = false;
               already4 = false;
            }
         
            else if (num_cups > ((a*b) + (a-1)*(b-1) + (a-2)*(b-2)) && (num_cups - ((a*b) + (a-1)*(b-1) + (a-2)*(b-2))) < difference && (b-1) > 0 && (a-1) > 0 && (a-2) > 0 && (b-2) > 0)
            {
               finalA = a;
               finalB = b;
               difference = num_cups - ((a*b) + (a-1)*(b-1) + (a-2)*(b-2));
               already3 = true;
               already2 = false;
               already4 = false;
            }
         
            else if (num_cups > ((a*b) + (a-1)*(b-1) + (a-2)*(b-2) + (a-3)*(b-3)) && (num_cups - ((a*b) + (a-1)*(b-1) + (a-2)*(b-2) + (a-3)*(b-3))) < difference && (a-1) > 0 && (b-1) > 0 && (a-2) > 0 && (b-2) > 0 && (a-3) > 0 && (b-3) > 0)
            {
               finalA = a;
               finalB = b;
               difference = num_cups - ((a*b) + (a-1)*(b-1) + (a-2)*(b-2) + (a-3)*(b-3));
               already4 = true;
               already3 = false;
               already2 = false;
            }
         }
      }
      
      if (already2)
      {
         cout << "First level: " << finalA << "x" << finalB << endl;
         cout << "Second level: " << finalA-1 << "x" << finalB-1 << endl;
         cout << "Cups left over: " << difference << endl;
         cout << "-----------------------" << endl;
      }
      
      else if (already3)
      {
         cout << "First level: " << finalA << "x" << finalB << endl;
         cout << "Second level: " << finalA-1 << "x" << finalB-1 << endl;
         cout << "Third level: " << finalA-2 << "x" << finalB-2 << endl;
         cout << "Cups left over: " << difference << endl;
         cout << "-----------------------" << endl;
      }
      
      else if (already4)
      {
         cout << "First level: " << finalA << "x" << finalB << endl;
         cout << "Second level: " << finalA-1 << "x" << finalB-1 << endl;
         cout << "Third level: " << finalA-2 << "x" << finalB-2 << endl;
         cout << "Fourth level: " << finalA-3 << "x" << finalB-3 << endl;
         cout << "Cups left over: " << difference << endl;
         cout << "-----------------------" << endl;
      }
   }
   
   return 0;
   
}