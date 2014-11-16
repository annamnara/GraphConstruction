GraphConstruction
=================
For any given dataset n*d , where n is the number of examples and d dimension of an example, we need to construct the Graph g=(V,E) where |V|=n and E is set of edges (Our focus is construction of "Weight Matrix W of size n*n" , each entry in W, W_ij denotes weight between node i and node j). In simple terms 

Input   : Data Matrix   n*d 
output  : Weight Matrix n*n 
Process : (a) Method for choosing how many edges needs to be connected to a node like k-NN and e-NN 
          (b) Distance Measure to compute distance between node i and node j, namely Euclidean distance, Gaussian 
              Kernel,Cosine Similarity, etc.

