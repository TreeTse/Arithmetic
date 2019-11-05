


//解法：使用快慢指针

Node* FindMToLastNode(Node* phead,int m){
    Node* cur = phead;
    Node* tmp = phead;
    for(int i = 0; i < m; i++){
        if(cur)
            cur = cur->next;
        else
            return NULL;
    }
    while(cur){
        cur = cur->next;
        tmp = tmp->next;
    }
    return tmp;
}



