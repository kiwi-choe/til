#include "Graph.h"
#include "MST.h"

int main( void )
{
    
    /*  ±×·¡ÇÁ »ýŒº     */
    Graph* graph      = createGraph();
    Graph* PrimMST    = createGraph();
    Graph* KruskalMST = createGraph();
   
    /*  Á€Á¡ »ýŒº */
    Vertex* A = createVertex( 'A' );
    Vertex* B = createVertex( 'B' );
    Vertex* C = createVertex( 'C' );
    Vertex* D = createVertex( 'D' );
    Vertex* E = createVertex( 'E' );
    Vertex* F = createVertex( 'F' );
    Vertex* G = createVertex( 'G' );
    Vertex* H = createVertex( 'H' );
    Vertex* I = createVertex( 'I' );

    /*  ±×·¡ÇÁ¿¡ Á€Á¡À» Ãß°¡ */
    addVertex( graph, A );
    addVertex( graph, B );
    addVertex( graph, C );
    addVertex( graph, D );
    addVertex( graph, E );
    addVertex( graph, F );
    addVertex( graph, G );
    addVertex( graph, H );
    addVertex( graph, I );

    /*  Á€Á¡°ú Á€Á¡À» °£Œ±Àž·Î ÀÕ±â */
    addEdge( A, createEdge(A, B, 35) );
    addEdge( A, createEdge(A, E, 247) );
    
    addEdge( B, createEdge(B, A, 35  ) );
    addEdge( B, createEdge(B, C, 126 ) );
    addEdge( B, createEdge(B, F, 150 ) );

    addEdge( C, createEdge(C, B, 126 ) );
    addEdge( C, createEdge(C, D, 117 ) );
    addEdge( C, createEdge(C, F, 162 ) );
    addEdge( C, createEdge(C, G, 220 ) );
    
    addEdge( D, createEdge(D, C, 117 ) );

    addEdge( E, createEdge(E, A, 247 ) );
    addEdge( E, createEdge(E, F, 82 ) );
    addEdge( E, createEdge(E, H, 98 ) );

    addEdge( F, createEdge(F, B, 150 ) );
    addEdge( F, createEdge(F, C, 162 ) );
    addEdge( F, createEdge(F, E, 82  ) );
    addEdge( F, createEdge(F, G, 154 ) );
    addEdge( F, createEdge(F, H, 120 ) );

    addEdge( G, createEdge(G, C, 220 ) );
    addEdge( G, createEdge(G, F, 154 ) );
    addEdge( G, createEdge(G, I, 106 ) );

    addEdge( H, createEdge(H, E, 98  ) );
    addEdge( H, createEdge(H, F, 120 ) );

    addEdge( I, createEdge(I, G, 106 ) );
    
    /*  Á€Á¡ BžŠ œÃÀÛ Á€Á¡Àž·Î ÇÏŽÂ ÃÖŒÒ œÅÀå Æ®ž®. */
    printf("Prim's Algorithm\n");
    prim(graph, B, PrimMST);
    printGraph ( PrimMST );

    printf("Kruskal's Algorithm...\n");
    kruskal(graph, KruskalMST);
    printGraph ( KruskalMST );
    
    /*  ±×·¡ÇÁ ŒÒžê */
    destroyGraph( PrimMST );
    destroyGraph( KruskalMST );
    destroyGraph( graph );

    return 0;
}