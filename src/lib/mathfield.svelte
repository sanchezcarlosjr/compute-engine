<script>
  import * as mathlive from 'mathlive'
  export let value;
  import { beforeUpdate } from "svelte";
  let mf;
  function updateInput() {
    if (mf !== undefined) {
      mf.setValue(value);
    }
  }
  beforeUpdate(() => updateInput());
</script>

<math-field bind:this="{mf}" readonly></math-field>
