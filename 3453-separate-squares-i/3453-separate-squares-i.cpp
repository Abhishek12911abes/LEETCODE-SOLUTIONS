class Solution {
public:
    double calculateArea(vector<int>& temp) {
        return 1.0 * temp[2] * temp[2];
    }

    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();

        double low = squares[0][1];
        double high = squares[0][1] + squares[0][2];

        for (int i = 0; i < n; i++) {
            low = min(low, (double)squares[i][1]);
            high = max(high, 1.0 * squares[i][1] + squares[i][2]);
        }

        double res = 0;

        for (int k = 0; k < 100; k++) {
            double mid = low + (high - low) / 2.0;

            double lowerArea = 0;
            double upperArea = 0;

            for (int i = 0; i < n; i++) {
                double y = squares[i][1];
                double side = squares[i][2];

                // Square completely above the line
                if (y >= mid) {
                    upperArea += calculateArea(squares[i]);
                }

                // Square completely below the line
                else if (y + side <= mid) {
                    lowerArea += calculateArea(squares[i]);
                }

                // Line passes through the square
                else {
                    double lowerHeight = mid - y;
                    double upperHeight = y + side - mid;

                    lowerArea += lowerHeight * side;
                    upperArea += upperHeight * side;
                }
            }

            if (lowerArea < upperArea) {
                low = mid;
            }
            else {
                res = mid;
                high = mid;
            }
        }

        return res;
    }
};