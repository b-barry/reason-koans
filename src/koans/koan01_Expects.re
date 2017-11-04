/* comments begin with /* and end with */ */
/* replace (todo ()) with something that makes the tests pass */
open Jest;
open Expect;
open Helpers;

type techno = {
  name: string
};


let koans = (_) =>
  describe(
    "Jest Expects",
    (_) => {
      /** Get familiar with jest espect */
     test("toBe checks that a value is what you expect", (_) => expect(todo()) |> toBe ("Hello"));
     test("toEqual expects two equal values", (_) =>{
       let reason = {name:"Reason"};
      expect(todo()) |> toEqual(reason);
     });
    }
  );
