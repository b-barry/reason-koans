open Helpers;

let koans = (_) =>
  Mocha.describe("Mathematical Operators") @@
  (
    (_) => {
      Mocha.it("abs gives the absolute value of a number") @@ ((_) => abs(todo()) |> Mocha.eq(3));
      Mocha.it("sqrt gives the square root of a Float") @@ ((_) => sqrt(todo()) |> Mocha.eq(3.0));
      Mocha.it("+ adds numbers") @@ ((_) => 1 + todo() |> Mocha.eq(3));
      Mocha.it("- subtracts numbers") @@ ((_) => 7 - todo() |> Mocha.eq(3));
      Mocha.it("* multiplies numbers") @@ ((_) => 4 * todo() |> Mocha.eq(24));
      Mocha.it("/. divides Floats") @@ ((_) => 5.0 /. todo() |> Mocha.eq(2.5));
      Mocha.it("/ divides Ints") @@ ((_) => 5 / todo() |> Mocha.eq(2));
      Mocha.it("mod performs modular arithmetic") @@ ((_) => todo() |> Mocha.eq(13 mod 5))
    }
  );
