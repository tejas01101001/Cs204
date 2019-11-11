1)make(v) - creates a new set consisting of the new element v
2)merge(a, b) - merges the two specified sets
3)find(v) - returns the representative  of the set that contains the element v.It is selected in each set by the data structure itself (and can change over time, namely after union_sets calls). This representative can be used to check if two elements are part of the same set of not. a and b are exactly in the same set, if find(a) == find(b). Otherwise they are in different sets.
4)Always connect the representative of the smaller set to the representative of the larger set . Using this strategy, the length of any chain will be O(logn), so we can find the representative of any element efficiently by following the corresponding chain.
5)UNION BY SIZE
void make(lli v)
{
  parent[v]=v;
  size[v]=1;
}

lli find(lli v)
{
  if(v==parent[v])return v;
  return parent[v]=find(parent[v]);
}

void merge(lli a,lli b)
{
  a=find(a);
  b=find(b);
  if(a!=b)
  {
    if(size[a]<size[b])swap(a,b);
    parent[b]=a;
    size[a]+=size[b];
  }
}
6)UNION BY RANK(depth)
void make(lli v)
{
  parent[v]=v;
  rank[v]=0;
}

lli find(lli v)
{
  if(v==parent[v])return v;
  return parent[v]=find(parent[v]);
}

void merge(lli a,lli b)
{
  a=find(a);
  b=find(b);
  if(a!=b)
  {
    if(rank[a]<rank[b])swap(a,b);
    parent[b]=a;
    if(rank[a]==rank[b])rank[a]++;
  }
}

APPLICATIONS:
1)Connected components in a graph
answer queries of the form (a,b) - "are the vertices a and b in the same connected component of the graph?"

2)Store additional information for each set
Like size,rank,representative

3)Search for connected components in an image
One of the applications of DSU is the following task: there is an image of n×m pixels. Originally all are white, but then a few black pixels are drawn. You want to determine the size of each white connected component in the final image.

For the solution we simply iterate over all white pixels in the image, for each cell iterate over its four neighbors, and if the neighbor is white call union_sets. Thus we will have a DSU with nm nodes corresponding to image pixels. The resulting trees in the DSU are the desired connected components.

The problem can also be solved by DFS or BFS, but the method described here has an advantage: it can process the matrix row by row (i.e. to process a row we only need the previous and the current row, and only need a DSU built for the elements of one row) in O(min(n,m)) memory.
