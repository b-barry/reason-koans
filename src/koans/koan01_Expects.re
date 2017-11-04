/* comments begin with /* and end with */ */
/* replace (todo ()) with something that makes the tests pass */
open Helpers;

let koans = (_) =>
  Mocha.describe(
    "Expects",
    (_) => {
      Mocha.it("Mocha.ok expects a true value", (_) => Mocha.ok(todo()));
      Mocha.it("Mocha.eq expects two equal values", (_) => Mocha.eq(1, todo()))
    }
  );
