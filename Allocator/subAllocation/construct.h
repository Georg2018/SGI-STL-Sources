﻿#pragma once
#include "new.h"//需要placement new

template <class T1,class T2>
inline void construct(T1* p, T2 value) {
	new(p) T1(value);
}

template <class T>
inline void destroy(T* p) {
	p->~T();
}

//设法利用traits批量析构对象
template <class ForwardIterator>
inline void destory(ForwardIterator beg, ForwardIterator end) {
	_destory(beg, end, value_type(first);
}

//判断元素是否有trivial destructor
template <class ForwardIterator,class T>
inline void _destory(ForwardIterator beg, ForwardIterator end, T*) {
	//_type_traits实现见迭代器一节
	using trivial_destructor = typename _type_traits<T>::has_trivial_destructor;
	_destory_aux(beg, end, trival_destructor());
}

//如果元素的value_type不存在non—trivial destructor
template <class ForwardIterator>
inline void _destory_aux(ForwardIterator beg, ForwardIterator end, _false_type) {
	for (; beg != end; ++beg)
		destroy(&*beg);//毕竟迭代器不是真正的地址
}

//存在trivial destructor
//如果对象的析构函数无关痛痒，那么反复调用它是一种效率上的巨大浪费
template <class ForwardIterator>
inline void _destroy_aux(ForwardIterator, ForwardIterator,_true_type) {}

//针对char*、wchar_t*的特化
inline void destory(char*, char*) {}
inline void destory(wchar_t*, wchar_t*) {}