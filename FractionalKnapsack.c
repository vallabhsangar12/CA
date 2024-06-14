#include <stdio.h>

// Function to calculate the maximum value that can be obtained
float maxProfit(float W, float wt[], float val[], int n) {
    // Convert weights and profits to integers for simplicity
    int i;
    float ratio[n];
    
    for (i = 0; i < n; i++) {
        ratio[i] = val[i] / wt[i]; // Value per unit weight
    }
    
    // Sort the array based on the ratio
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[i]) {
                float temp_ratio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp_ratio;
                
                float temp_wt = wt[i];
                wt[i] = wt[j];
                wt[j] = temp_wt;
                
                float temp_val = val[i];
                val[i] = val[j];
                val[j] = temp_val;
            }
        }
    }
    
    // Calculate the total profit
    float final_profit = 0.0;
    for (i = 0; i < n; i++) {
        if (W == 0)
            break;
        
        // If entire item can be accommodated
        if (wt[i] <= W) {
            final_profit += val[i];
            W -= wt[i];
        } else { // Only fraction of item can be accommodated
            final_profit += val[i] * (W / wt[i]);
            W = 0;
        }
    }
    
    return final_profit;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    float val[n], wt[n], W;
    printf("Enter the maximum weight of the knapsack: ");
    scanf("%f", &W);
    
    printf("Enter the weights and corresponding profit:\n");
    for(int i=0; i<n; i++){
        scanf("%f %f", &wt[i], &val[i]);
    }
    
    float max_value = maxProfit(W, wt, val, n);
    printf("Maximum profit that can be achieved = %.2f\n", max_value);
    
    return 0;
}
