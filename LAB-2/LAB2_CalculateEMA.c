//write a simple c program for calculation of exponential mean average
#include <stdio.h>
#include <math.h>

// Function to calculate EMA
double calculateEMA(double prices[], int period, int dataSize) {
    if (dataSize < period) {
        printf("Not enough data to calculate EMA\n");
        return -1;
    }
    
    double multiplier = 2.0 / (period + 1); // EMA multiplier
    double ema = 0.0;
    
    // Calculate the initial SMA (used as first EMA value)
    for (int i = 0; i < period; i++) {
        ema += prices[i];
    }
    ema /= period;
    
    // Calculate EMA for the rest of the data
    for (int i = period; i < dataSize; i++) {
        ema = ((prices[i] - ema) * multiplier) + ema;
    }
    
    return ema;
}

int main() {
    int period;
    int dataSize;
    
    printf("Enter the number of data points: ");
    scanf("%d", &dataSize);
    
    double prices[dataSize];
    printf("Enter %d stock prices:\n", dataSize);
    for (int i = 0; i < dataSize; i++) {
        scanf("%lf", &prices[i]);
    }
    
    printf("Enter the EMA period: ");
    scanf("%d", &period);
    
    double ema = calculateEMA(prices, period, dataSize);
    if (ema != -1) {
        printf("The Exponential Moving Average (EMA) is: %.2f\n", ema);
    }
    
    return 0;
}

