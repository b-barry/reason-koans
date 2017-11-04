open Helpers;

type point = {
  x: int,
  y: int
};

let makePoint = (x, y) => {x, y};

let point = makePoint(1, 2);

let koans = (_) =>
  Mocha.describe("Records") @@
  (
    (_) => {
      Mocha.it("a record is a set of named fields") @@
      ((_) => {x: todo(), y: todo()} |> Mocha.eq({x: 1, y: 2}));
      Mocha.it("you can access a field with dot notation") @@ ((_) => todo() |> Mocha.eq(point.x));
      Mocha.it("you can extract data with destructuring too") @@
      (
        (_) =>
          (
            switch point {
            | _ => todo()
            }
          )
          |> Mocha.eq(1)
      )
    }
  );
