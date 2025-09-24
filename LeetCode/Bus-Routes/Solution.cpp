    if(source == target) { return 0; }

    class Node {
        int route;
        int busNo;

        public Node(int route, int busNo) {
            this.route = route;
            this.busNo = busNo;
        }
    }

    ArrayList<ArrayList<Node>> adj = new ArrayList<>(100001);
    Queue<Node> que = new LinkedList<>();
    int[] minRoutes = new int[100001];
    Arrays.fill(minRoutes, Integer.MAX_VALUE);

    for(int i=0; i<=100001; i++) {
        adj.add(new ArrayList<Node>());
    }

    for(int i=0; i<routes.length; i++) {
        int len = routes[i].length;
        for(int j=0; j<len; j++) {
            int src = routes[i][j];
            int dest = (routes[i][(j+1) % len]);
            adj.get(src).add(new Node(dest, i));

            if(src == source) {
                que.add(new Node(src, i));
                minRoutes[source] = 1;
            }
        }
    }


    // if(adj.get(source).size() == 0) {
    //     return 0;
    // }

    

    while(que.size() > 0) {
        Node currNode = que.poll();

        int currPath = currNode.route;
        int currBusNo = currNode.busNo;

        for(Node node : adj.get(currPath)) {
            
            if(node.busNo == currBusNo && minRoutes[node.route] > minRoutes[currPath]) {
               minRoutes[node.route] = minRoutes[currPath];
               que.add(new Node(node.route, node.busNo));
            } else if (minRoutes[node.route] >= minRoutes[currPath] + 1 ) {
                minRoutes[node.route] = minRoutes[currPath] + 1;
                que.add(new Node(node.route, node.busNo));
            }
        }
    }

    if(target >= minRoutes.length) {
        return -1;
    }

    return (minRoutes[target] == Integer.MAX_VALUE) ? -1 : minRoutes[target];
}