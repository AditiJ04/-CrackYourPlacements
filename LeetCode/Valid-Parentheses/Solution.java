1import java.util.*;
2
3class Solution {
4
5    public int get(char c) {
6        if (c == '(') {
7            return 1;
8        }
9
10        if (c == '{') {
11            return 2;
12        }
13
14        if (c == '[') {
15            return 3;
16        }
17
18        if (c == ')') {
19            return -1;
20        }
21
22        if (c == '}') {
23            return -2;
24        }
25
26        return -3;
27    }
28
29    public boolean isValid(String s) {
30        int n = s.length();
31
32        Stack<Integer> st = new Stack<>();
33
34        for (char ch : s.toCharArray()) {
35            int b = get(ch);
36
37            if (b > 0) {
38                st.push(b);
39            } else {
40                if (!st.empty()) {
41                    int a = st.peek();
42                    if (a == Math.abs(b)) {
43                        st.pop();
44                    } else {
45                        return false;
46                    }
47                }
48
49                else
50                    return false;
51            }
52        }
53
54        if (st.empty())
55            return true;
56
57        return false;
58    }
59}