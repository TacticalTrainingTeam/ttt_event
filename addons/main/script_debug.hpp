/**
STACK TRACING
**/
//#define ENABLE_CALLSTACK
//#define ENABLE_PERFORMANCE_COUNTERS
//#define DEBUG_EVENTS

#ifdef ENABLE_CALLSTACK
    #define CALLSTACK(function) {if(ACE_IS_ERRORED) then { ['AUTO','AUTO'] call ACE_DUMPSTACK_FNC; ACE_IS_ERRORED = false; }; ACE_IS_ERRORED = true; ACE_STACK_TRACE set [ACE_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, ACE_CURRENT_FUNCTION, 'ANON', _this]]; ACE_STACK_DEPTH = ACE_STACK_DEPTH + 1; ACE_CURRENT_FUNCTION = 'ANON'; private _ret = _this call ##function; ACE_STACK_DEPTH = ACE_STACK_DEPTH - 1; ACE_IS_ERRORED = false; _ret;}
    #define CALLSTACK_NAMED(function, functionName) {if(ACE_IS_ERRORED) then { ['AUTO','AUTO'] call ACE_DUMPSTACK_FNC; ACE_IS_ERRORED = false; }; ACE_IS_ERRORED = true; ACE_STACK_TRACE set [ACE_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, ACE_CURRENT_FUNCTION, functionName, _this]]; ACE_STACK_DEPTH = ACE_STACK_DEPTH + 1; ACE_CURRENT_FUNCTION = functionName; private _ret = _this call ##function; ACE_STACK_DEPTH = ACE_STACK_DEPTH - 1; ACE_IS_ERRORED = false; _ret;}
    #define DUMPSTACK ([__FILE__, __LINE__] call ACE_DUMPSTACK_FNC)

    #define FUNC(var1) {if(ACE_IS_ERRORED) then { ['AUTO','AUTO'] call ACE_DUMPSTACK_FNC; ACE_IS_ERRORED = false; }; ACE_IS_ERRORED = true; ACE_STACK_TRACE set [ACE_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, ACE_CURRENT_FUNCTION, 'TRIPLES(ADDON,fnc,var1)', _this]]; ACE_STACK_DEPTH = ACE_STACK_DEPTH + 1; ACE_CURRENT_FUNCTION = 'TRIPLES(ADDON,fnc,var1)'; private _ret = _this call TRIPLES(ADDON,fnc,var1); ACE_STACK_DEPTH = ACE_STACK_DEPTH - 1; ACE_IS_ERRORED = false; _ret;}
    #define EFUNC(var1,var2) {if(ACE_IS_ERRORED) then { ['AUTO','AUTO'] call ACE_DUMPSTACK_FNC; ACE_IS_ERRORED = false; }; ACE_IS_ERRORED = true; ACE_STACK_TRACE set [ACE_STACK_DEPTH, [diag_tickTime, __FILE__, __LINE__, ACE_CURRENT_FUNCTION, 'TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)', _this]]; ACE_STACK_DEPTH = ACE_STACK_DEPTH + 1; ACE_CURRENT_FUNCTION = 'TRIPLES(DOUBLES(PREFIX,var1),fnc,var2)'; private _ret = _this call TRIPLES(DOUBLES(PREFIX,var1),fnc,var2); ACE_STACK_DEPTH = ACE_STACK_DEPTH - 1; ACE_IS_ERRORED = false; _ret;}
#else
    #define CALLSTACK(function) function
    #define CALLSTACK_NAMED(function, functionName) function
    #define DUMPSTACK ; /* disabled */
#endif
