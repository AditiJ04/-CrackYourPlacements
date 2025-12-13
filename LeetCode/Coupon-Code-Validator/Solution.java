1import java.util.*;
2class Solution {
3    public boolean isAlpha(String s) {
4        if (s == null || s.isEmpty())
5            return false;
6        for (char ch : s.toCharArray()) {
7            if (!Character.isLetterOrDigit(ch) && ch != '_')
8                return false;
9        }
10        return true;
11    }
12
13    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {
14
15        List<String> result = new ArrayList<>();
16        List<Map.Entry<Integer, String>> v = new ArrayList<>();
17
18        int n = code.length;
19
20        for (int i = 0; i < n; i++) {
21            if (isActive[i] && isAlpha(code[i])) {
22                int category = 0;
23                if (businessLine[i].equals("electronics"))
24                    category = 1;
25                else if (businessLine[i].equals("grocery"))
26                    category = 2;
27                else if (businessLine[i].equals("pharmacy"))
28                    category = 3;
29                else if (businessLine[i].equals("restaurant"))
30                    category = 4;
31                else
32                    continue;
33
34                v.add(new AbstractMap.SimpleEntry<>(category, code[i]));
35            }
36        }
37
38        v.sort((a, b) -> {
39            if (!a.getKey().equals(b.getKey()))
40                return a.getKey() - b.getKey();
41            return a.getValue().compareTo(b.getValue());
42        });
43
44        for (Map.Entry<Integer, String> e : v) {
45            result.add(e.getValue());
46        }
47
48        return result;
49    }
50}