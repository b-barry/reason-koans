open Helpers;

let koans = (_) =>
  Mocha.describe("Logical Operators") @@
  (
    (_) => {
      Mocha.it("not negates a boolean") @@ ((_) => ! todo() |> Mocha.eq(false));
      Mocha.it("&& is a logical AND") @@ ((_) => (true && todo()) |> Mocha.ok);
      Mocha.it("|| is a logical OR") @@ ((_) => (false || todo()) |> Mocha.ok)
    }
  );
