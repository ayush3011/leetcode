string fractionAddition(string expr) {
        int num = 0;
        int deno = 1;
        int n = expr.length();
        int i = 0;

        while (i < n) {
            int currNum = 0;
            int currDeno = 0;

            bool isNeg = expr[i] == '-';

            if (expr[i] == '+' || expr[i] == '-') {
                i++;
            }

            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currNum = (currNum * 10) + val;
                i++;
            }

            i++; // skiping the '/' character

            if (isNeg == true) {
                currNum *= -1;
            }

            while (i < n && isdigit(expr[i])) {
                int val = expr[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }

            num = num * currDeno + currNum * deno;
            deno = deno * currDeno;
        }

        int GCD = abs(__gcd(num, deno)); // handling the negative gcd
        num /= GCD;
        deno /= GCD;

        return to_string(num) + "/" + to_string(deno);
}
