class Solution {
public:
    double waterOverflow(int poured, int row, int glass) {
        double v[101][101] = {0.0};
        v[0][0] = poured;
        
        for(int i = 0; i < 100; ++i) {
            for(int j = 0; j <= i; ++j) {
                double q = (v[i][j] - 1) / 2.0;
                // glass is >= 1
                if(v[i][j] >= 1) {
                    // split  (v[i][j] - 1) into next level
                    v[i+1][j] += q;
                    v[i+1][j+1] += q;
                    v[i][j] = 1;
                }
            }
        }
        return v[row-1][glass-1];
    }
};