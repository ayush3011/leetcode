string losingPlayer(int x, int y) {
        if (y < 4)
            return "Bob";
        int flag = 1;
        while (x >= 1 && y >= 4) {
            x = x - 1;
            y = y - 4;
            flag = flag * (-1);
        }
        if (flag == -1)
            return "Alice";
        else
            return "Bob";
}
