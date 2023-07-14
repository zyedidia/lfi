package main

type Builder struct {
	list *OpList
	cur  *OpNode
}

func NewBuilder(list *OpList) *Builder {
	b := &Builder{
		list: list,
	}
	return b
}

func (b *Builder) Locate(op *OpNode) {
	b.cur = op
}

func (b *Builder) Add(op *OpNode) *OpNode {
	b.cur = b.list.InsertAfter(b.cur, op)
	return b.cur
}

func (b *Builder) AddBefore(op *OpNode) *OpNode {
	b.cur = b.list.InsertBefore(b.cur, op)
	return b.cur
}
