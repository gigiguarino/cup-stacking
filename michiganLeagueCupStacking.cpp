//
//  michiganLeagueCupStacking.cpp
//  Created by Gabrielle Guarino on 9/13/15.

#include <string>
#include <iostream>
using namespace std;

int main(void)
{
   // first level:
   // 8 or 9 high
   // 3+ wide
   
   // second level:
   // if first row is 8, second is 7 high
   // if 9, second is 8 high
   // how wide first row is - 1
   
   // only go to a third level if low on space
   // or > 70
   
   int num_cups;
   string low_on_space_question;
   bool low_on_space = false;
   
   cout << "How many cups?: ";
   cin >> num_cups;
   
   cout << "Are you low on space? (y/n): ";
   cin >> low_on_space_question;
   cout << endl;
   
   if (num_cups == 1)
   {
      cout << "1 cup? Just set it down." << endl;
      return 0;
   }
   
   int l1x = 0;
   int l1y = 0;
   int finalA = 0;
   int finalB = 0;
   int current_num;
   bool prime = false;
   bool found = false;
   bool four_levels = false;
   int difference = 1000;
   
   if (low_on_space_question == "y")
   {
      low_on_space = true;
   }
   
   
   
   
   
   if (low_on_space && num_cups > 27 && num_cups < 150)
   {
      // three levels
      // possibily four
      bool three_levels = false;
      
      for (int a = 7; a <= 9 && !found; a++)
      {
         l1y = a;
         
         for (int b = 2; b <= 5 && !found; b++)
         {
            l1x = b;
            current_num = (a*b) + ((a-1)*(b-1));
            
            if (current_num == num_cups)
            {
               finalA = l1y;
               finalB = l1x;
               difference = 0;
               found = true;
            }
            
            else if (num_cups - current_num < difference && num_cups - current_num > 0)
            {
               finalA = l1y;
               finalB = l1x;
               difference = num_cups - current_num;
            }
         }
      }
      
      found = false;
      
      for (int a = 7; a <= 9 && !found; a++)
      {
         l1y = a;
         
         for (int b = 2; b <= 6 && !found; b++)
         {
            l1x = b;
            current_num = (a*b) + ((a-1)*(b-1)) + ((a-2)*(b-2));
            
            if (current_num == num_cups)
            {
               finalA = l1y;
               finalB = l1x;
               difference = 0;
               three_levels = true;
               found = true;
            }
            
            else if (num_cups - current_num < difference && num_cups - current_num > 0)
            {
               finalA = l1y;
               finalB = l1x;
               difference = num_cups - current_num;
               three_levels = true;
            }
         }
      }
      
      found = false;
      
      for (int a = 7; a <= 9 && !found; a++)
      {
         l1y = a;
         
         for (int b = 4; b <= 5 && !found; b++)
         {
            l1x = b;
            current_num = (a*b) + ((a-1)*(b-1)) + ((a-2)*(b-2)) + ((a-3)*(b-3));
            
            if (current_num == num_cups)
            {
               finalA = l1y;
               finalB = l1x;
               difference = 0;
               four_levels = true;
               three_levels = true;
               found = true;
            }
            
            else if (num_cups - current_num < difference && num_cups - current_num > 0)
            {
               finalA = l1y;
               finalB = l1x;
               four_levels = true;
               three_levels = true;
               difference = num_cups - current_num;
            }
         }
      }
      
      cout << "First level: " << finalA << "x" << finalB << endl;
      cout << "Second level: " << finalA - 1 << "x" << finalB - 1 << endl;
      
      if (three_levels)
      {
         cout << "Third level: " << finalA - 2 << "x" << finalB - 2 << endl;
      }
      
      if (four_levels)
      {
         cout << "Fourth level: " << finalA - 3 << "x" << finalB - 3 << endl;
      }
      
      if (difference != 0)
      {
         cout << "Cups left over: " << difference << endl;
      }
      
      cout << endl;
      
      return 0;
   }
   
   
   
   
   
   else if (num_cups > 200)
   {
      // possibly four levels
      
      for (int a = 8; a <= 9 && !found; a++)
      {
         l1y = a;
         
         for (int b = 3; b <= 15 && !found; b++)
         {
            l1x = b;
            current_num = (a*b) + ((a-1)*(b-1)) + ((a-2)*(b-2));
            
            if (current_num == num_cups)
            {
               finalA = l1y;
               finalB = l1x;
               difference = 0;
               found = true;
            }
            
            else if (num_cups - current_num < difference && num_cups - current_num > 0)
            {
               finalA = l1y;
               finalB = l1x;
               difference = num_cups - current_num;
            }
         }
      }
      
      found = false;
      
      for (int a = 8; a <= 9 && !found; a++)
      {
         l1y = a;
         
         for (int b = 3; b <= 15 && !found; b++)
         {
            l1x = b;
            current_num = (a*b) + ((a-1)*(b-1)) + ((a-2)*(b-2)) + ((a-3)*(b-3));
            
            if (current_num == num_cups)
            {
               finalA = l1y;
               finalB = l1x;
               difference = 0;
               four_levels = true;
               found = true;
            }
            
            else if (num_cups - current_num < difference && num_cups - current_num > 0)
            {
               finalA = l1y;
               finalB = l1x;
               difference = num_cups - current_num;
               four_levels = true;
            }
         }
      }
      
      cout << "First level: " << finalA << "x" << finalB << endl;
      cout << "Second level: " << finalA - 1 << "x" << finalB - 1 << endl;
      cout << "Third level: " << finalA - 2 << "x" << finalB - 2 << endl;
      
      if (four_levels)
      {
         cout << "Fourth level: " << finalA - 3 << "x" << finalB - 3 << endl;
      }
      
      if (difference != 0)
      {
         cout << "Cups left over: " << difference << endl;
      }
      
      cout << endl;
      
      return 0;
   }
   
   
   
   
   
   else if (num_cups > 70)
   {
      // three levels
      int c;
      int d;
      
      if (num_cups > 100)
      {
         c = 20;
         d = 7;
      }
      
      else
      {
         c = 15;
         d = 6;
      }
      
      for (int a = d; a <= 9 && !found; a++)
      {
         l1y = a;
         
         for (int b = 3; b <= c && !found; b++)
         {
            l1x = b;
            current_num = (a*b) + ((a-1)*(b-1)) + ((a-2)*(b-2));
            
            if (current_num == num_cups)
            {
               finalA = l1y;
               finalB = l1x;
               difference = 0;
               found = true;
            }
            
            else if (num_cups - current_num < difference && num_cups - current_num > 0)
            {
               finalA = l1y;
               finalB = l1x;
               difference = num_cups - current_num;
            }
         }
      }
      
      cout << "First level: " << finalA << "x" << finalB << endl;
      cout << "Second level: " << finalA - 1 << "x" << finalB - 1 << endl;
      cout << "Third level: " << finalA - 2 << "x" << finalB - 2 << endl;
      
      if (difference != 0)
      {
         cout << "Cups left over: " << difference << endl;
      }
      
      cout << endl;
      
      return 0;
   }
   
   
   
   
   
   
   else if (num_cups < 38)
   {
      // one level only
      // THIS BLOCK WORKS WELL
      
      if (num_cups == 11 || num_cups == 13)
      {
         cout << "Small, prime number. No nice way of arranging these cups." << endl;
         return 0;
      }
      
      for (int a = 9; a > 1; a--)
      {
         if ((num_cups/a)*a == num_cups && num_cups/a <= 9)
         {
            finalA = a;
            finalB = num_cups/a;
            difference = 0;
            found = true;
            break;
         }
      }
      
      if (!found)
      {
         for (int b = 3; b <= 9; b++)
         {
            l1y = b;
            
            for (int c = 4; c <= 9; c++)
            {
               l1x = c;
               current_num = (b*c);
               
               if (num_cups - current_num < difference && num_cups - current_num > 0)
               {
                  finalA = l1y;
                  finalB = l1x;
                  difference = num_cups - current_num;
               }
            }
         }
      }

      cout << "First level: " << finalA << "x" << finalB << endl;
      
      if (difference != 0)
      {
         cout << "Cups left over: " << difference << endl;
      }
      
      cout << endl;
      
      return 0;
   }
   
   
   
   
   else
   {
      // two levels
      // WORKS PRETTY WELL, BUT SOMETIMES THERE ARE LEFTOVER CUPS OF 6
      // KINDA A LARGE NUMBER.. CAN WORK ON IN FUTURE
      
      for (int a = 5; a <= 9 && !found; a++)
      {
         l1y = a;
         
         for (int b = 3; b <= 15 && !found; b++)
         {
            l1x = b;
            current_num = (a*b) + ((a-1)*(b-1));
            
            if (current_num == num_cups)
            {
               finalA = l1y;
               finalB = l1x;
               difference = 0;
               found = true;
            }
            
            else if (num_cups - current_num < difference && num_cups - current_num > 0)
            {
               finalA = l1y;
               finalB = l1x;
               difference = num_cups - current_num;
            }
         }
      }
      
      cout << "First level: " << finalA << "x" << finalB << endl;
      cout << "Second level: " << finalA - 1 << "x" << finalB - 1 << endl;
      
      if (difference != 0)
      {
         cout << "Cups left over: " << difference << endl;
      }
      
      cout << endl;
      
      return 0;
   }
   
   return 0;
}
