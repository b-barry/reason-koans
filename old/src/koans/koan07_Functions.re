open Helpers;

open Containers;

let add = (x, y) => x + y;

let subtract = (x, y) => x - y;

let subtractFrom4 = subtract(4);

let always5 = Fun.const(5);

let subtract4 = (Fun.flip(subtract))(4);

let multiplyBy2 = (x) => 2 * x;

let koans = (_) =>
  Mocha.describe("Functions") @@
  (
    (_) => {
      Mocha.it("the id function returns whatever it is passed") @@
      ((_) => todo() |> Mocha.eq(Fun.id(4)));
      Mocha.it("functions are defined as 'name args => implementation'") @@
      (
        (_) => {
          let add1 = (x) => x + 1;
          add1(todo()) |> Mocha.eq(5)
        }
      );
      Mocha.it("functions may have an optional type signature") @@
      (
        (_) => {
          let add1 = (_: int) : int => todo();
          add1(3) |> Mocha.eq(5)
        }
      );
      Mocha.it("anonymous functions are defined with '\\args -> implementation'") @@
      ((_) => subtract(8, todo()) |> Mocha.eq(5));
      Mocha.it("anonymous functions may be defined inline") @@
      ((_) => ((x, y) => x - y)(8, todo()) |> Mocha.eq(5));
      Mocha.it("functions passed some values return curried functions") @@
      ((_) => subtractFrom4(todo()) |> Mocha.eq(1));
      Mocha.it("the always function returns its first argument, no matter what the second is") @@
      ((_) => todo() |> Mocha.eq(always5(4)));
      Mocha.it("the flip function flips the order of the first two arguments of a function") @@
      ((_) => todo() |> Mocha.eq(subtract4(9)));
      Mocha.it("f @@ a applies the function f to the arg a") @@
      ((_) => todo() |> Mocha.eq(subtract4 @@ add(1, 9)));
      Mocha.it("a |> f applies the function f to the arg a") @@
      ((_) => todo() |> Mocha.eq(add(1, 9) |> subtract4));
      Mocha.it("Fun.(%) composes function g with function f") @@
      (
        (_) => {
          let multiplyAndSubtract = Fun.(%)(subtract4, multiplyBy2);
          todo() |> Mocha.eq @@ multiplyAndSubtract(9)
        }
      )
    }
  );
