open Helpers;

let koans = (_) =>
  Mocha.describe("Number Conversions") @@
  (
    (_) => {
      Mocha.it("float converts an int to a float") @@ ((_) => todo() |> Mocha.eq(float(5)));
      Mocha.it("floor rounds a float down") @@ ((_) => todo() |> Mocha.eq(floor(3.6)));
      Mocha.it("floor rounds a negative float down") @@ ((_) => todo() |> Mocha.eq(floor((-3.6))));
      Mocha.it("ceiling rounds a float up") @@ ((_) => todo() |> Mocha.eq(ceil(3.6)));
      Mocha.it("ceiling rounds a negative float up") @@ ((_) => todo() |> Mocha.eq(ceil((-3.6))));
      Mocha.it("truncate converts a float to an int (rounding towards 0)") @@
      ((_) => todo() |> Mocha.eq(truncate(3.6)));
      Mocha.it("truncate converts a float to an int (rounding towards 0)") @@
      ((_) => todo() |> Mocha.eq(truncate((-3.6))))
    }
  );
