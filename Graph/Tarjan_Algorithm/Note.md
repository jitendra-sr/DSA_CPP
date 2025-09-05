1. Tarjan’s approach is a general DFS-based framework using discovery times (tin) and low-link values (low), developed by Robert Tarjan.
2. It is mainly used for finding important structures like SCC, Cut-Edges, Cut-Points in graphs in linear time O(V + E).
3. **_Tarjan’s algorithm (originally & in narrow sense) is the algorithm to find SCCs._**

## Core Idea (Low-Link Concept)

- During DFS, each node gets a discovery time (tin[]) and a low-link value (low[]).
- low[v] = the earliest discovered node reachable from v (including back edges).
- The reason SCCs, bridges, and articulation points can all be solved with Tarjan’s low-link idea is because:

  ## 1. Common Ground: DFS Tree + Back Edges

  - When we run DFS, we build a DFS tree.
  - Graph edges can be of two types:
    - Tree edges → part of DFS tree.
    - Back edges → edges that connect a node to an ancestor in the DFS tree.

  The key question in all three problems is: \
   👉 _Does removing this node/edge break connectivity or isolate a component?_

  ## 2. The Low-Link Value

  - tin[u] = discovery time of u.
  - low[u] = earliest discovered vertex reachable from u or its descendants (via back edges).
  - So:
    - If a child can "climb back" to an ancestor, it’s still connected.
    - If it cannot, that’s where components or cut structures appear.

  ## 3. How the Same Idea Solves 3 Problems

  | Problem             | Graph Type | Condition (using low[] and tin[])                                                        | Intuition                                                                       |
  | ------------------- | ---------- | ---------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
  | SCCs                | Directed   | If low[u] == tin[u], u is the root of an SCC. Pop stack until u.                         | Nodes that can reach each other form a strongly connected component.            |
  | Bridges             | Undirected | If low[v] > tin[u], then edge (u,v) is a bridge.                                         | Child v cannot reach back to u or above → removing (u,v) disconnects the graph. |
  | Articulation Points | Undirected | If (low[v] >= tin[u]) for a child v, then u is an articulation point (except root case). | If v cannot reach above u, removing u cuts v’s subtree away.                    |

  ## 4. Intuition Connection

  - SCC: cutting into strongly connected "islands".
  - Bridge: an edge critical for keeping connectivity between two parts.
  - Articulation point: a node critical for keeping connectivity.

  All three rely on checking: \
   👉 _Can the DFS subtree of v connect back to u or its ancestors via a back edge?_ \
   If yes → safe (still connected). \
   If no → that’s where the SCC ends, or a bridge/cut vertex is found.

**Note** \
SCCs can also be find by Kosaraju algorithm in same time & space complexity, but tarjan is faster as it find sccs in one pass.

**Resource**
[YouTube](https://www.youtube.com/watch?v=ZeDNSeilf-Y&ab_channel=Techdose)
