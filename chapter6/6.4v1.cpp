int CanReachEndMinSteps(const vector<int>& max_advance_steps) {
    int max_index = 0, curr = 0, last_index = max_advance_steps.size()-1, steps = 0, lastReach;
    while (curr <= max_index && max_index < last_index) {
        lastReach = max_index;
        while (curr <= lastReach) {
            if (max_advance_steps[curr] + curr > max_index)
                max_index = max_advance_steps[curr] + curr;
            curr++;
        }
        steps++;
    }
    return (max_index < last_index) ? -1 : steps;
}
