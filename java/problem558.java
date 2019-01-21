/*
update (using methond combineSameNode())
56 / 58 test cases passed. 
*/

/*
!!!!!!!!!bug still exist!!!!!!!!!!!!!!!! 
leetcode test results: only 27 / 58 test cases passed
*/

import java.util.Stack;
// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {}

    public Node(boolean _val,boolean _isLeaf,Node _topLeft,Node _topRight,Node _bottomLeft,Node _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
class Solution {
    public Node intersect(Node quadTree1, Node quadTree2) {
        Stack<Node> newFather=new Stack<>();
        Node root=new Node();
        newFather.push(root);

        Stack<Node> st1=new Stack<Node>();
        Stack<Node> st2=new Stack<Node>();
        st1.push(quadTree1);st2.push(quadTree2);
        while(!st1.empty()){
            Node temp1=st1.peek();
            Node temp2=st2.peek();
            Node fr=newFather.peek();

            if(!temp1.isLeaf&&!temp2.isLeaf){
                newFather.pop();
                for(int i=0;i<4;i++){
                    Node temp=new Node();
                    switch (i) {
                        case 3:
                            fr.topLeft=temp;
                            break;
                        case 2:
                            fr.topRight=temp;
                            break;
                        case 1:
                            fr.bottomLeft=temp;
                            break;
                        case 0:
                            fr.bottomRight=temp;
                            break;
                        default:
                            break;
                    }
                    newFather.push(temp);
                }
                st1.pop();
                st1.push(temp1.bottomRight);
                st1.push(temp1.bottomLeft);
                st1.push(temp1.topRight);
                st1.push(temp1.topLeft);

                st2.pop();
                st2.push(temp2.bottomRight);
                st2.push(temp2.bottomLeft);
                st2.push(temp2.topRight);
                st2.push(temp2.topLeft);      
            }else if(temp1.isLeaf&&!temp2.isLeaf){
                if(temp1.val){
                    fr.isLeaf=true;fr.val=true;
                    st1.pop();st2.pop();newFather.pop();
                }else{
                    newFather.pop();
                    for(int i=0;i<4;i++){
                        Node temp=new Node();
                        switch (i) {
                            case 3:
                                fr.topLeft=temp;
                                break;
                            case 2:
                                fr.topRight=temp;
                                break;
                            case 1:
                                fr.bottomLeft=temp;
                                break;
                            case 0:
                                fr.bottomRight=temp;
                                break;
                            default:
                                break;
                        }
                        newFather.push(temp);
                    }
                    st2.pop();
                    st2.push(temp2.bottomRight);
                    st2.push(temp2.bottomLeft);
                    st2.push(temp2.topRight);
                    st2.push(temp2.topLeft); 
                    
                    st1.pop();
                    st1.push(temp1);
                    st1.push(temp1);
                    st1.push(temp1);
                    st1.push(temp1); 
                }

            }else if(!temp1.isLeaf&&temp2.isLeaf){
                if(temp2.val){
                    fr.isLeaf=true;fr.val=true;
                    st1.pop();st2.pop();newFather.pop();
                }else{
                    newFather.pop();
                    for(int i=0;i<4;i++){
                        Node temp=new Node();
                        switch (i) {
                            case 3:
                                fr.topLeft=temp;
                                break;
                            case 2:
                                fr.topRight=temp;
                                break;
                            case 1:
                                fr.bottomLeft=temp;
                                break;
                            case 0:
                                fr.bottomRight=temp;
                                break;
                            default:
                                break;
                        }
                        newFather.push(temp);
                    }
                    st1.pop();
                    st1.push(temp1.bottomRight);
                    st1.push(temp1.bottomLeft);
                    st1.push(temp1.topRight);
                    st1.push(temp1.topLeft);

                    st2.pop();
                    st2.push(temp2);
                    st2.push(temp2);
                    st2.push(temp2);
                    st2.push(temp2);     
                }

            }else{
                fr.isLeaf=true;fr.val=temp1.val||temp2.val;
                st1.pop();st2.pop();newFather.pop();
            }

        }
        st1.push(root);
        boolean tag=false;;
        while(true){
            if(st1.isEmpty()){
                if(!tag){
                    break;
                }else{
                    st1.push(root);
                }
            }
            tag=false;
            Node temp=st1.peek();
            if(temp!=null){
                tag=combineSameNode(temp);
                st1.pop();
                st1.push(temp.bottomRight);
                st1.push(temp.bottomLeft);
                st1.push(temp.topRight);
                st1.push(temp.topLeft);
            }else{
                st1.pop();
            }
        }
        /*del node with same child*/
        /*
            st1.push(root);
            while(!st1.isEmpty()){
                Node temp=st1.peek();
                if(temp==null){
                    break;
                }else if(!temp.isLeaf
                &&valOfNode(temp.topLeft)==valOfNode(temp.topRight)
                &&valOfNode(temp.topLeft)==valOfNode(temp.bottomLeft)
                &&valOfNode(temp.topLeft)==valOfNode(temp.bottomRight)
                &&valOfNode(temp.topLeft)!=-1
                ){
                    temp.isLeaf=true;
                    if(valOfNode(temp.topLeft)==1){
                        temp.val=true;
                    }else{
                        temp.val=false;
                    }
                    temp.topLeft=null;temp.topRight=null;
                    temp.bottomLeft=null;temp.bottomRight=null;
                    st1.pop();
                }else{
                    st1.pop();
                    st1.push(temp.bottomRight);
                    st1.push(temp.bottomLeft);
                    st1.push(temp.topRight);
                    st1.push(temp.topLeft);
                }
            }
        */

        return root;
    }
    public static boolean combineSameNode(Node node){
        if(node.isLeaf){
            return false;
        }else if(node.bottomLeft.isLeaf
        &&node.bottomRight.isLeaf
        &&node.topLeft.isLeaf
        &&node.topRight.isLeaf){
            if(node.bottomLeft.val==node.bottomRight.val
            &&node.bottomLeft.val==node.topLeft.val
            &&node.bottomLeft.val==node.topRight.val){
                node.isLeaf=true;node.val=node.bottomLeft.val;
                node.topLeft=null;node.topRight=null;
                node.bottomLeft=null;node.bottomRight=null;
                return true;
            }
        }
        return false;
    }
    public static byte valOfNode(Node node){
        if(node.isLeaf){
            if(node.val){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(valOfNode(node.topLeft)==valOfNode(node.topRight)&&valOfNode(node.topLeft)
            ==valOfNode(node.bottomLeft)&&valOfNode(node.topLeft)==valOfNode(node.bottomRight)){
              return valOfNode(node.topLeft); 
            }else{
                return -1;
            }
        }

    }

}

