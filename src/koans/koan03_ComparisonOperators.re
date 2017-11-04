open Helpers;

let koans = (_) =>
  Mocha.describe(
    "Comparison Operators",
    (_) => {
      Mocha.it("== tests for equality") @@ ((_) => 1 == todo() |> Mocha.ok);
      Mocha.it("!= tests for inequality") @@ ((_) => 1 != todo() |> Mocha.ok);
      Mocha.it("< tests for less than") @@ ((_) => 1 < todo() |> Mocha.ok);
      Mocha.it("> tests for greater than") @@ ((_) => 2 > todo() |> Mocha.ok);
      Mocha.it("<= tests for less than or equal") @@ ((_) => 1 <= todo() |> Mocha.ok);
      Mocha.it(">= tests for greater than or equal") @@ ((_) => 2 >= todo() |> Mocha.ok);
      Mocha.it("floats are comparable") @@ ((_) => 1.0 < todo() |> Mocha.ok);
      Mocha.it("strings are comparable") @@ ((_) => "1" == todo() |> Mocha.ok);
      Mocha.it("chars are comparable") @@ ((_) => '1' == todo() |> Mocha.ok);
      Mocha.it("max returns the max of two args") @@ ((_) => max(1, 2) |> Mocha.eq(todo()));
      Mocha.it("min returns the min of two args") @@ ((_) => min(1, 2) |> Mocha.eq(todo()));
      Mocha.it("compare returns -1 for LT, 0 for EQ and 1 for GT") @@
      ((_) => compare(1, 2) |> Mocha.eq(todo()))
    }
  );
