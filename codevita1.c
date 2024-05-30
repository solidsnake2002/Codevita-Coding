#include <stdio.h>

// Function to compute the valency of a compound
int get_valency(char compound) {
	 int valency = compound ;

    // Keep reducing to one digit
    while (valency >= 10) {
        int sum = 0;

        // Compute the digit sum
        while (valency > 0) {
            sum += valency % 10;
            valency /= 10;
        }

        valency = sum;
    }

    return valency;
}

// Function to find all combinations to reach the equivalent point
void find_combinations(char compound1, char compound2, int equivalent_point) {
    int val1 = get_valency(compound1);
    int val2 = get_valency(compound2);
	int count=0;
	int mul2;
    for (mul2 = 0; mul2 <= equivalent_point / val2; ++mul2) 
	{
        int remaining_val1 = equivalent_point - (mul2 * val2);
        int mul1 = remaining_val1 / val1;

        if ((mul1 * val1 + mul2 * val2 == equivalent_point) && mul1!=0 && mul2!=0) 
		{
            printf("%c%d %c%d\n", compound1, mul1, compound2, mul2);
            count ++;
        }
    }
    if(count==0)
    	printf("Not possible");
}

int main() {
    // Input
    char compound[3];
    int equivalent_point;

    scanf("%s", compound);
    scanf("%d", &equivalent_point);

    // Split the compound into two elements
    char compound1 = compound[0];
    char compound2 = compound[1];

    // Find combinations
    find_combinations(compound1, compound2, equivalent_point);

    return 0;
}

