


// 
// xvalue comes from:
//     • std::move(x)
//     • static_cast<T&&>(x)
//     • functions returning T&& (rare)
// 
// prvalue comes from:
//     1. Literal or built-in computation
//     2. Temporary / constructor call
//     3. Returning by value:
//          – return expr; where expr is prvalue
//          – return x; where x is an lvalue (creates prvalue)


//
// xvalue comes from:
//

// 1. std::move(x)
// 		Turns an lvalue into an xvalue.

std::string s;
std::move(s);      // xvalue


// 2. static_cast<T&&>(x)
//		Also turns an lvalue into an xvalue.

static_cast<Widget&&>(w)   // xvalue


// 3. Functions returning T&&
// 		Rare, but possible:

Widget&& foo();  // -> function that return rvalue ref
 
foo();     // xvalue



// 
// prvalue comes from:
//

// 1. Literal or built-in computation
// 		These have no identity.

42
true
3 + 5



// 2. Temporary / constructor call

// 		This includes:
// 
// 			- Temporary creation
// 			- Direct initialization
// 			- Copy/move initialization from a temporary


Widget()                   // temporary, prvalue
Widget("hi")               // prvalue
std::string("abc")         // prvalue

// And yes, this also includes:

Widget w = Widget();       // RHS is a prvalue


// 3. Returning by value
//
// 		(a) return expr; where expr is prvalue

Widget makeWidget()
{
	return Widget();      // prvalue
}

return x + y;         // prvalue

// 		(b) return x; where x is an lvalue
// 			This creates a prvalue, even though x is an lvalue:

Widget makeWidget()
{
	Widget w;
	return w;             // prvalue materialized from w
}

// This is the tricky one, but you got it right.