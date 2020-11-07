/*
    Date: 2020/7/14
    Owner: Chun-Yeh, Lin
    Note: angle problem
*/

// Version 1: Runtime 0ms / Memory Usage: 6.1MB(34.12%)

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans;
        double h_angle, m_angle;
        m_angle = minutes * (double)(360/60);
        h_angle =  (hour * (double)(360/12)) + minutes * (double)(0.5);
        if(h_angle>=360) h_angle = h_angle-360;
        ans = min(abs(h_angle-m_angle), 360-abs(h_angle-m_angle));
        // cout << h_angle << endl;
        // cout << m_angle << endl;
        return ans;
    }
};