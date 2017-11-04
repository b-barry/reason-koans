open Helpers;

open Containers;

let koans = (_) =>
  Mocha.describe("Result") @@
  (
    (_) => {
      Mocha.it("results represent the result of a function") @@
      ((_) => Result.Ok(todo()) |> (==)(Result.Ok(42)) |> Mocha.ok);
      Mocha.it("but could be an error") @@
      ((_) => Result.Error(todo()) |> (==)(Result.Error("there was an error")) |> Mocha.ok);
      Mocha.it("a result can be converted to a maybe") @@
      ((_) => Some(todo()) |> (==)(Result.toOption(Result.Ok(42))) |> Mocha.ok);
      Mocha.it("but an error will become nothing") @@
      ((_) => todo() |> (==)(Result.toOption(Result.Error("error"))) |> Mocha.ok);
      Mocha.it("a maybe can also be converted to a result") @@
      ((_) => Result.Ok(todo()) |> (==)(Result.fromOption(Some(42))) |> Mocha.ok);
      Mocha.it("and will become an error if there is nothing") @@
      ((_) => Result.Error() |> (==)(Result.fromOption(None)) |> Mocha.ok)
    }
  );
