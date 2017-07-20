#include "LinkedList.h"

Node* createNode(Vertex* NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  /*  µ¥ÀÌÅÍžŠ ÀúÀåÇÑŽÙ. */
    NewNode->NextNode = NULL; /*  ŽÙÀœ ³ëµå¿¡ ŽëÇÑ Æ÷ÀÎÅÍŽÂ NULL·Î ÃÊ±âÈ­ ÇÑŽÙ. */

    return NewNode;           /*  ³ëµåÀÇ ÁÖŒÒžŠ ¹ÝÈ¯ÇÑŽÙ. */
}

/*  ³ëµå ŒÒžê */
void SLL_DestoryNode(Node* Node)
{
    free(Node);
}

/*  ³ëµå Ãß°¡ */
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    /*  Çìµå ³ëµå°¡ NULLÀÌ¶óžé »õ·Î¿î ³ëµå°¡ Head */
    if ( (*Head) == NULL ) 
    {        
        *Head = NewNode;
    } 
    else
    {
        /*  Å×ÀÏÀ» Ã£ŸÆ NewNodežŠ ¿¬°áÇÑŽÙ. */
        Node* Tail = (*Head);
        while ( Tail->NextNode != NULL )
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

/*  ³ëµå »ðÀÔ */
void SLL_InsertAfter(Node** Current, Node** NewNode)
{
    (*NewNode)->NextNode = (*Current)->NextNode;
    (*Current)->NextNode = *NewNode;
}

void  insertNewHead(Node** Head, Node** NewHead)
{
    if ( Head == NULL )
    {
        (*Head) = (*NewHead);    
    }
    else
    {
        (*NewHead)->NextNode = (*Head);
        (*Head) = (*NewHead);
    }
}


/*  ³ëµå ÁŠ°Å */
void SLL_RemoveNode(Node** Head, Node** Remove)
{
    if ( *Head == *Remove )
    {
        *Head = (*Remove)->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while ( Current != NULL && Current->NextNode != (*Remove) )
        {
            Current = Current->NextNode;
        }

        if ( Current != NULL )
            Current->NextNode = (*Remove)->NextNode;
    }
}

/*  ³ëµå Åœ»ö */
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while ( Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

/*  ³ëµå Œö ŒŒ±â */
int SLL_GetNodeCount(Node* Head)
{
    unsigned int  Count = 0;
    Node*         Current = Head;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}