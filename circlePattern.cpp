#include <bits/stdc++.h>
using namespace std;
/*
    *    
  *****  
 ******* 
 ******* 
*********
 ******* 
 ******* 
  *****  
    *    
*/
// int main() {
//     int radius=4;
//     // cin>>radius;  // Adjust the radius as needed
//     int diameter = 2 * radius;
//     int center = radius;

//     for (int i = 0; i <= diameter; i++) {
//         for (int j = 0; j <= diameter; j++) {
//             // Calculate the distance from the center
//             double distance = sqrt(pow(i - center, 2) + pow(j - center, 2));
//             // Check if the point is inside or on the boundary of the circle
//             if (distance <= radius) {
//                 cout << "*";
//             } else {
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
/*
  ***  
 *   * 
*     *
*     *
*     *
 *   * 
  ***  
*/
int main() {
    int radius = 3;
    int diameter = 2 * radius;
    int center = radius;

    for (int i = 0; i <= diameter; i++) {
        for (int j = 0; j <= diameter; j++) {
            double distance = sqrt(pow(i - center, 2) + pow(j - center, 2));
            if (distance >= radius - 0.5 && distance <= radius + 0.5) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
