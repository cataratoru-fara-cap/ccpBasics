#include "Message.h"
#include "QueueCirc.h"

class MessageSender
{
private:
    /* data */
public:
    void putMessage(QueueCirc<Message>& q, Message m){
        q.enqueue(m);
        
    }
    MessageSender(){

    }
    ~MessageSender(){}
};

class MessageReceiver
{
private:
    /* data */
public:
    Message openMessage(QueueCirc<Message>& q){
        return q.dequeue();
    }

    MessageReceiver(){}
    ~MessageReceiver(){}
};


int main()
{
    Message m1  = Message("Gabi", "Alex", "Buna", 1, 1, 2002);
    Message m2  = Message("Ana", "Alex", "Hey", 1, 1, 2002);
    Message m3  = Message("Cara", "Alex", "Saloot", 1, 1, 2002);

    QueueCirc <Message> q;

    MessageSender sender;
    MessageReceiver receiver;

    sender.putMessage(q, m1);
    cout << q.peek().getContent() << endl;
    cout << "message " << receiver.openMessage(q).getContent() << endl;
    //The calls to the queue work, but the content is void EXCEPT FOR THE DATE???, needs fixing
    return 0;
}

