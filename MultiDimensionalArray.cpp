#include <iostream>

int main() {
    //  matrix[row][column] i.e lr = leftrow(leftright); mrc  //     
    int matrix[3][3] = {

              /* Column 0, 1, 2 * /
/* Row 0 */   { 1, 2, 3 },
/* Row 1 */   { 4, 5, 6 },
/* Row 2 */   { 7, 8, 9 }

    };

    // To access an element, you need two [row][column]
    // Let's access the number 
    std::cout << "The element at row 0, column 0 is: " << matrix[0][0] << std::endl;
    std::cout << "The element at row 0, column 1 is: " << matrix[0][1] << std::endl;
    std::cout << "The element at row 0, column 2 is: " << matrix[0][2] << std::endl;

    std::cout << "The element at row 1, column 0 is: " << matrix[1][0] << std::endl;
    std::cout << "The element at row 1, column 1 is: " << matrix[1][1] << std::endl;
    std::cout << "The element at row 1, column 2 is: " << matrix[1][2] << std::endl;

    std::cout << "The element at row 2, column 0 is: " << matrix[2][0] << std::endl;
    std::cout << "The element at row 2, column 1 is: " << matrix[2][1] << std::endl;
    std::cout << "The element at row 2, column 2 is: " << matrix[2][2] << std::endl;

    std::string MuSers[3][3] = {

                    /* Column 0, 1, 2 * /   
/* Row 0 */        {"1", "Adish", "CA"},
/* Row 1 */        {"2", "Tesla", "NY"},
/* Row 2 */        {"3", "Tatay", "NJ"}
    };

    std::cout << "\n--- User List ---" << std::endl;
    std::cout << "ID: " << MuSers[0][0] << " Name: " << MuSers[0][1] << " State: " << MuSers[0][2] << std::endl;
    std::cout << "ID: " << MuSers[1][0] << " Name: " << MuSers[1][1] << " State: " << MuSers[1][2] << std::endl;
    std::cout << "ID: " << MuSers[2][0] << " Name: " << MuSers[2][1] << " State: " << MuSers[2][2] << std::endl;


	 // Loop through Muitidimensional Array
	 std::string letters[2][4] = {
		 {"A", "B", "C", "D"},
		 {"E", "F", "G", "H"}
	 };

	 for (int i = 0; i < 2; i++)
	 {
		 for (int j = 0; j < 4; j++)
		 {
			 std::cout << letters[i][j] << std::endl;
		 }
	 }

    return 0;
}