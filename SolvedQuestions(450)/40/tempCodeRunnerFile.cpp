int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
        int max1 = 0, index;
	    for (int i = 0; i < n; i++){
            int row1 = 0;
            for(int j = 0; j < m; j++){
                if(arr[i][j]==1){
                    row1++;
                }
            }
            if(row1>max1){
                max1=row1;
                index = i;
            }
        }
        return index;
	}