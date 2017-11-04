open Helpers;

open Containers;

let koans = (_) =>
  Mocha.describe("Option") @@
  (
    (_) => {
      Mocha.it("an option represents a value that may be nothing") @@
      ((_) => todo() |> (==)(None) |> Mocha.ok);
      Mocha.it("or the value could be something") @@
      ((_) => Some(todo()) |> (==)(Some(5)) |> Mocha.ok);
      Mocha.it("withDefault can be used to get the value from an option") @@
      ((_) => todo() |> (==)(Option.getOr(~default=3, Some(5))) |> Mocha.ok);
      Mocha.it("but will give the default value if there is nothing") @@
      ((_) => todo() |> (==)(Option.getOr(~default=3, None)) |> Mocha.ok);
      Mocha.it("map will transform the value in a option") @@
      ((_) => Some(todo()) |> (==)(Option.map((n) => n / 2, Some(4))) |> Mocha.ok);
      Mocha.it("but will not transform a nothing") @@
      ((_) => todo() |> (==)(Option.map((n) => n / 2, None)) |> Mocha.ok)
    }
  );
