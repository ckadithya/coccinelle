@@
//local function fn1;
identifier fn1;
identifier cs, ev;
@@

// supposed to drop the prototype as well

- fn1(struct IsdnCardState *cs, int ev) {
-   ...
-   test_and_set_bit(ev, &cs->event);
-   schedule_work(&cs->work);
- }

@@
//struct IsdnCardState *cs;
//int ev;
expression cs, ev;
@@

- fn1(cs,ev)
+ sched_d_event(cs,ev)

@@
//struct IsdnCardState *cs;
//int ev;
expression cs, ev;
@@

- test_and_set_bit(ev, &cs->event);
- schedule_work(&cs->work);
+ sched_d_event(cs,ev);

