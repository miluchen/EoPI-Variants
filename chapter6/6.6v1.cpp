int VDeleteDuplicates(int m, vector<int> *A_ptr) {
    vector<int> &A = *A_ptr;
    if (A.empty())
        return 0;

    int idx = 1, tot_count = 0, count;
    for (int i=1; i<A.size(); i++) {
        if (A[i] == A[i-1])
            tot_count++;
        else if (A[i] != A[i-1]) {
            count = (tot_count == m) ? min(2,m) : tot_count;
            for (int j=1; j<count; j++)
                A[idx++] = A[i-1];
            A[idx++] = A[i];
            tot_count = 1;
        }
    }
    count = (tot_count == m ) ? min(2,m) : tot_count;
    for (int i=1; i<count; i++)
        A[idx++] = A.back();

    return idx;
}
