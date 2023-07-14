package main

type List[V any] struct {
	Front, Back *Node[V]
}

type Node[V any] struct {
	Value       V
	Leader      bool
	IdxEstimate int
	Prev, Next  *Node[V]
}

func (l *List[V]) PushBack(n *Node[V]) {
	n.Next = nil
	n.Prev = l.Back
	if l.Back != nil {
		l.Back.Next = n
	} else {
		l.Front = n
	}
	l.Back = n
}

func (l *List[V]) Remove(n *Node[V]) {
	if n.Next != nil {
		n.Next.Prev = n.Prev
	} else {
		l.Back = n.Prev
	}
	if n.Prev != nil {
		n.Prev.Next = n.Next
	} else {
		l.Front = n.Next
	}
}

func (l *List[V]) InsertAfter(n *Node[V], next *Node[V]) *Node[V] {
	next.Next = n.Next
	next.Prev = n
	if n.Next != nil {
		n.Next.Prev = next
	} else {
		l.Back = next
	}
	n.Next = next
	return next
}

func (l *List[V]) InsertBefore(n *Node[V], prev *Node[V]) *Node[V] {
	prev.Next = n
	prev.Prev = n.Prev
	if n.Prev != nil {
		n.Prev.Next = prev
	} else {
		l.Front = prev
	}
	n.Prev = prev
	return prev
}

type OpNode = Node[Op]
type OpList = List[Op]

func NewNode(op Op) *OpNode {
	return &OpNode{
		Value: op,
	}
}

type BlockNode = Node[Block]
type BlockList = List[Block]
