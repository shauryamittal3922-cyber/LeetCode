int maxProfit(int* prices, int pricesSize) {
    int min = prices[0];
    int max = 0;

    for(int i = 1; i < pricesSize; i++){
        if(prices[i] < min) min = prices[i];
        else if(max < (prices[i] - min)) max = prices[i] - min;
    }

    return max;
}