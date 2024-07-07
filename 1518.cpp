int numWaterBottles(int numBottles, int numExchange) {
        int bottlesDrank = numBottles, emptyBottles = numBottles;

        while (emptyBottles / numExchange) {
            bottlesDrank = bottlesDrank + (emptyBottles / numExchange);
            emptyBottles =
                (emptyBottles / numExchange) + (emptyBottles % numExchange);
        }

        return bottlesDrank;
}
