auto solve = [&](void) -> void {
        ll n; cin >> n;
        vector<ll> arr(n);
        for(auto &it: arr) cin >> it;
        ll sum = accumulate(arr.begin(), arr.end(), 0LL);
        ll N = n / 2;
        vector<vector<ll>> left(N + 1), right(N + 1);
        // All Possible Sums in left and right part generating and storing using bit-masking
        for(ll mask = 0; mask < (1 << N); mask++){
            ll idx = 0, left_sum = 0, right_sum = 0;
            for(ll i = 0; i < N; i++){
                if(mask & (1 << i)){
                    idx++;
                    left_sum += arr[i];
                    right_sum += arr[N + i];
                }
            }
            left[idx].push_back(left_sum);
            right[idx].push_back(right_sum);               // WHAT IS THIS ??? 
             /*
                Each sum will be stored in a 2D vector left and right where left[k] contains the 
                subset sums that use exactly k elements from the left_part, and similarly, right[k] for the right_part. 
            */
        }
        
        for(int i = 0; i <= N; i++){
            sort(right[i].begin(), right[i].end());
        }

        ll res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));
        // iterating to left part
        for(ll idx = 1; idx < N; idx++){
            for(auto &a: left[idx]){
                int b = (sum - (2 * a)) / 2;                                 // WHY??
                /*
                REASON: If a subset of size sz is chosen from the left with sum as lSum, 
                        we will need a subset of size N - sz from the right with sum as 
                        rSum to make it a subset of size N. Now, the question is which 
                        subset to choose from right to make the absolute difference minimum. 
                        Total sum of the subset after choosing the right subset will be
                        lSum + rSum, therefore the absolute difference will be
                        totalSum - 2*(lSum + rSum) = totalSum - 2*lSum - 2*rSum. The minimum
                        possible value of this is 0 at rSum = (totalSum - 2*lSum)/2. Hence, 
                        we need to choose that subset from right which is as close to this 
                        rSum as possible.
                */
                int rightidx = N - idx; 
                auto &v = right[rightidx];
                auto itr = lower_bound(v.begin(), v.end(), b);  // binary search to get closest element
                if(itr != v.end()){
                    res = min(res, abs(sum - 2 * (a + *itr)));
                }
            }
        }
        cout << res << endl;
    };

    solve();
